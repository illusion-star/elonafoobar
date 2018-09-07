#include "dialog_decoder.hpp"
#include "../lua_env/lua_env.hpp"
#include "dialog.hpp"
#include "dialog_data.hpp"

namespace elona
{

optional<DialogData> DialogDecoder::decode(const std::string& id)
{
    return decode(id, *lua::lua.get());
}

static std::pair<std::string, std::string> _parse_id(
    const std::string& datatype_mod_name,
    const std::string& datatype_name,
    const std::string& id)
{
    // TODO dry
    auto colon_pos = id.find(":");
    if (colon_pos == std::string::npos)
    {
        throw std::runtime_error("Bad ID \"" + id + "\"");
    }

    std::string datatype_fqn = id.substr(0, colon_pos);
    std::string datatype_id = id.substr(colon_pos + 1);

    auto period_pos = datatype_fqn.find(".");
    if (period_pos == std::string::npos)
    {
        throw std::runtime_error("Bad datatype name \"" + datatype_fqn + "\"");
    }

    std::string mod_name = datatype_fqn.substr(0, period_pos);
    std::string name = datatype_fqn.substr(period_pos + 1);
    if (datatype_mod_name != mod_name || datatype_name != name)
    {
        throw std::runtime_error(
            "Expected id of format \"" + datatype_mod_name + "." + datatype_name
            + "\", got \"" + mod_name + "." + name + "\"");
    }

    period_pos = datatype_id.find(".");
    if (period_pos == std::string::npos)
    {
        throw std::runtime_error("Bad datatype name \"" + datatype_fqn + "\"");
    }

    return {datatype_id.substr(0, period_pos),
            datatype_id.substr(period_pos + 1)};
}

optional<DialogData> DialogDecoder::decode(
    const std::string& id,
    lua::LuaEnv& lua)
{
    try
    {
        sol::table dialog_table =
            *lua.get_registry_manager().get_table("core", "dialog");

        std::string mod_name;
        std::string data_id;
        std::tie(mod_name, data_id) = _parse_id("core", "dialog", id);

        sol::table dialog_table_data = dialog_table[mod_name][data_id];

        return decode(dialog_table_data, lua);
    }
    catch (const std::exception& e)
    {
        txtef(ColorIndex::red);
        txt(id + ": Dialog decoding error: " + e.what());
        return none;
    }
}

DialogData DialogDecoder::decode(sol::table table, lua::LuaEnv& lua)
{
    DialogData::map_type nodes;
    std::string full_id = table["_full_id"];

    sol::table nodes_table = table["nodes"];
    for (const auto& pair : nodes_table)
    {
        DialogNode the_dialog_node;

        std::string node_name = pair.first.as<std::string>();
        sol::table node_data = pair.second.as<sol::table>();

        the_dialog_node.behavior = std::make_shared<DialogNodeBehavior>();

        std::string node_id = full_id + "." + node_name;
        the_dialog_node.id = node_id;

        sol::object node_text = node_data["text"];
        if (node_text != sol::lua_nil)
        {
            if (node_text.is<std::string>())
            {
                the_dialog_node.text.emplace_back(node_text.as<std::string>());
            }
            else if (node_text.is<sol::table>())
            {
                for (const auto& pair : node_text.as<sol::table>())
                {
                    std::string text = pair.second.as<std::string>();
                    the_dialog_node.text.emplace_back(text);
                }
            }
        }

        int behaviors = 0;
        if (node_data["generator"] != sol::lua_nil)
        {
            std::string callback_generator = node_data["generator"];
            if (!lua.get_export_manager().has_function(callback_generator))
            {
                throw std::runtime_error(
                    full_id + ": Node \"" + node_name
                    + "\" has unknown Lua callback " + callback_generator);
            }
            the_dialog_node.behavior =
                std::make_shared<DialogNodeBehaviorGenerator>(
                    callback_generator);
            behaviors++;
        }
        if (node_data["redirector"] != sol::lua_nil)
        {
            // TODO dry
            std::string callback_redirector = node_data["redirector"];
            if (!lua.get_export_manager().has_function(callback_redirector))
            {
                throw std::runtime_error(
                    full_id + ": Node \"" + node_name
                    + "\" has unknown Lua callback " + callback_redirector);
            }
            the_dialog_node.behavior =
                std::make_shared<DialogNodeBehaviorRedirector>(
                    callback_redirector);
            behaviors++;
        }
        if (node_data["inherit_choices"] != sol::lua_nil)
        {
            // TODO dry
            std::string node_id_for_choices = node_data["inherit"];
            the_dialog_node.behavior =
                std::make_shared<DialogNodeBehaviorInheritChoices>(
                    node_id_for_choices);
            behaviors++;
        }

        if (behaviors > 1)
        {
            throw std::runtime_error(
                full_id + ": Only one of \"generator\", \"redirector\", or \"inherit_choices\" can be used at a time");
        }

        if (node_data["run_before"] != sol::lua_nil)
        {
            // TODO dry
            std::string callback_before = node_data["run_before"];
            if (!lua.get_export_manager().has_function(callback_before))
            {
                throw std::runtime_error(
                    full_id + ": Node \"" + node_name
                    + "\" has unknown Lua callback " + callback_before);
            }
            the_dialog_node.callback_before = callback_before;
        }

        if (node_data["run_after"] != sol::lua_nil)
        {
            // TODO dry
            std::string callback_after = node_data["run_after"];
            if (!lua.get_export_manager().has_function(callback_after))
            {
                throw std::runtime_error(
                    full_id + ": Node \"" + node_name
                    + "\" has unknown Lua callback " + callback_after);
            }
            the_dialog_node.callback_after = callback_after;
        }

        sol::object node_choices = node_data["choices"];
        if (node_choices != sol::lua_nil)
        {
            if (node_choices.is<std::string>())
            {
                if (node_choices.as<std::string>() == "End")
                {
                    // TODO: move "bye" text into locale
                    the_dialog_node.choices.emplace_back("bye"s, none);
                }
            }
            else if (node_choices.is<sol::table>())
            {
                sol::table node_choices_table = node_choices.as<sol::table>();
                for (const auto& pair : node_choices_table)
                {
                    sol::table choice_data = pair.second.as<sol::table>();
                    std::string text_key = choice_data["text"];
                    std::string next_node = choice_data["node"];

                    if (text_key == ""s || next_node == ""s)
                    {
                        throw std::runtime_error(
                            full_id + ": Expected \"text\" and \"node\" fields for choice in node \""s
                            + node_name + "\"");
                    }

                    if (next_node == "End")
                    {
                        the_dialog_node.choices.emplace_back(text_key, none);
                    }
                    else
                    {
                        the_dialog_node.choices.emplace_back(
                            text_key, next_node);
                    }
                }
            }
        }

        nodes.insert(std::make_pair(node_id, std::move(the_dialog_node)));
    }

    std::string starting_node = full_id + "._start";
    if (nodes.find(starting_node) == nodes.end())
    {
        throw std::runtime_error(
            full_id + ": Cannot find starting dialog node " + starting_node);
    }

    DialogData the_dialog(nodes, starting_node);
    return the_dialog;
}

} // namespace elona
