/* clang-format off */
template <typename Archive>
void serialize(Archive& _putit_archive_)
{
#define PUTIT_SERIALIZE_FIELD(field_name) _putit_archive_(this->field_name, #field_name)
    PUTIT_SERIALIZE_FIELD(state_);
    PUTIT_SERIALIZE_FIELD(position);
    PUTIT_SERIALIZE_FIELD(next_position);
    PUTIT_SERIALIZE_FIELD(time_to_revive);
    PUTIT_SERIALIZE_FIELD(vision_flag);
    PUTIT_SERIALIZE_FIELD(image);
    PUTIT_SERIALIZE_FIELD(sex);
    PUTIT_SERIALIZE_FIELD(relationship);
    PUTIT_SERIALIZE_FIELD(turn_cost);
    PUTIT_SERIALIZE_FIELD(current_speed);
    PUTIT_SERIALIZE_FIELD(item_which_will_be_used);
    PUTIT_SERIALIZE_FIELD(portrait);
    PUTIT_SERIALIZE_FIELD(interest);
    PUTIT_SERIALIZE_FIELD(time_interest_revive);
    PUTIT_SERIALIZE_FIELD(personality);
    PUTIT_SERIALIZE_FIELD(impression);
    PUTIT_SERIALIZE_FIELD(talk_type);
    PUTIT_SERIALIZE_FIELD(height);
    PUTIT_SERIALIZE_FIELD(weight);
    PUTIT_SERIALIZE_FIELD(birth_year);
    PUTIT_SERIALIZE_FIELD(nutrition);
    PUTIT_SERIALIZE_FIELD(can_talk);
    PUTIT_SERIALIZE_FIELD(quality);
    PUTIT_SERIALIZE_FIELD(turn);
    PUTIT_SERIALIZE_FIELD(id);
    PUTIT_SERIALIZE_FIELD(vision_distance);
    PUTIT_SERIALIZE_FIELD(enemy_id);
    PUTIT_SERIALIZE_FIELD(gold);
    PUTIT_SERIALIZE_FIELD(platinum_coin);
    PUTIT_SERIALIZE_FIELD(equipment_type);
    PUTIT_SERIALIZE_FIELD(melee_attack_type);
    PUTIT_SERIALIZE_FIELD(fame);
    PUTIT_SERIALIZE_FIELD(experience);
    PUTIT_SERIALIZE_FIELD(required_experience);
    PUTIT_SERIALIZE_FIELD(speed_percentage);
    PUTIT_SERIALIZE_FIELD(level);
    PUTIT_SERIALIZE_FIELD(speed_percentage_in_next_turn);
    PUTIT_SERIALIZE_FIELD(skill_bonus);
    PUTIT_SERIALIZE_FIELD(total_skill_bonus);
    PUTIT_SERIALIZE_FIELD(inventory_weight);
    PUTIT_SERIALIZE_FIELD(max_inventory_weight);
    PUTIT_SERIALIZE_FIELD(inventory_weight_type);
    PUTIT_SERIALIZE_FIELD(max_level);
    PUTIT_SERIALIZE_FIELD(karma);
    PUTIT_SERIALIZE_FIELD(hp);
    PUTIT_SERIALIZE_FIELD(max_hp);
    PUTIT_SERIALIZE_FIELD(sp);
    PUTIT_SERIALIZE_FIELD(max_sp);
    PUTIT_SERIALIZE_FIELD(mp);
    PUTIT_SERIALIZE_FIELD(max_mp);
    PUTIT_SERIALIZE_FIELD(heal_value_per_nether_attack);
    PUTIT_SERIALIZE_FIELD(god_id);
    PUTIT_SERIALIZE_FIELD(piety_point);
    PUTIT_SERIALIZE_FIELD(praying_point);
    PUTIT_SERIALIZE_FIELD(sum_of_equipment_weight);
    PUTIT_SERIALIZE_FIELD(special_attack_type);
    PUTIT_SERIALIZE_FIELD(rate_to_pierce);
    PUTIT_SERIALIZE_FIELD(rate_of_critical_hit);
    PUTIT_SERIALIZE_FIELD(speed_correction_value);
    PUTIT_SERIALIZE_FIELD(original_relationship);
    PUTIT_SERIALIZE_FIELD(pv);
    PUTIT_SERIALIZE_FIELD(dv);
    PUTIT_SERIALIZE_FIELD(hit_bonus);
    PUTIT_SERIALIZE_FIELD(damage_bonus);
    PUTIT_SERIALIZE_FIELD(pv_correction_value);
    PUTIT_SERIALIZE_FIELD(dv_correction_value);
    PUTIT_SERIALIZE_FIELD(damage_reaction_info);
    PUTIT_SERIALIZE_FIELD(emotion_icon);
    PUTIT_SERIALIZE_FIELD(current_map);
    PUTIT_SERIALIZE_FIELD(current_dungeon_level);
    PUTIT_SERIALIZE_FIELD(related_quest_id);
    PUTIT_SERIALIZE_FIELD(direction);
    PUTIT_SERIALIZE_FIELD(period_of_contract);
    PUTIT_SERIALIZE_FIELD(hire_count);
    PUTIT_SERIALIZE_FIELD(insanity);
    PUTIT_SERIALIZE_FIELD(curse_power);
    PUTIT_SERIALIZE_FIELD(extra_attack);
    PUTIT_SERIALIZE_FIELD(extra_shot);
    PUTIT_SERIALIZE_FIELD(decrease_physical_damage);
    PUTIT_SERIALIZE_FIELD(nullify_damage);
    PUTIT_SERIALIZE_FIELD(cut_counterattack);
    PUTIT_SERIALIZE_FIELD(anorexia_count);
    PUTIT_SERIALIZE_FIELD(continuous_action);
    PUTIT_SERIALIZE_FIELD(stops_continuous_action_if_damaged);
    PUTIT_SERIALIZE_FIELD(quality_of_performance);
    PUTIT_SERIALIZE_FIELD(tip_gold);
    PUTIT_SERIALIZE_FIELD(character_role);
    PUTIT_SERIALIZE_FIELD(shop_rank);
    PUTIT_SERIALIZE_FIELD(continuous_action_target);
    PUTIT_SERIALIZE_FIELD(shop_store_id);
    PUTIT_SERIALIZE_FIELD(time_to_restore);
    PUTIT_SERIALIZE_FIELD(cnpc_id);
    PUTIT_SERIALIZE_FIELD(initial_position);
    PUTIT_SERIALIZE_FIELD(hate);
    PUTIT_SERIALIZE_FIELD(ai_calm);
    PUTIT_SERIALIZE_FIELD(ai_move);
    PUTIT_SERIALIZE_FIELD(ai_dist);
    PUTIT_SERIALIZE_FIELD(ai_act_sub_freq);
    PUTIT_SERIALIZE_FIELD(ai_heal);
    PUTIT_SERIALIZE_FIELD(element_of_unarmed_attack);
    PUTIT_SERIALIZE_FIELD(poisoned);
    PUTIT_SERIALIZE_FIELD(sleep);
    PUTIT_SERIALIZE_FIELD(paralyzed);
    PUTIT_SERIALIZE_FIELD(blind);
    PUTIT_SERIALIZE_FIELD(confused);
    PUTIT_SERIALIZE_FIELD(fear);
    PUTIT_SERIALIZE_FIELD(dimmed);
    PUTIT_SERIALIZE_FIELD(drunk);
    PUTIT_SERIALIZE_FIELD(bleeding);
    PUTIT_SERIALIZE_FIELD(wet);
    PUTIT_SERIALIZE_FIELD(insane);
    PUTIT_SERIALIZE_FIELD(sick);
    PUTIT_SERIALIZE_FIELD(gravity);
    PUTIT_SERIALIZE_FIELD(choked);
    PUTIT_SERIALIZE_FIELD(furious);
    PUTIT_SERIALIZE_FIELD(growth_buffs);
    PUTIT_SERIALIZE_FIELD(body_parts);
    PUTIT_SERIALIZE_FIELD(normal_actions);
    PUTIT_SERIALIZE_FIELD(special_actions);
    PUTIT_SERIALIZE_FIELD(buffs);
    PUTIT_SERIALIZE_FIELD(attr_adjs);
    PUTIT_SERIALIZE_FIELD(_flags);
    PUTIT_SERIALIZE_FIELD(_156);
    PUTIT_SERIALIZE_FIELD(_203);
    PUTIT_SERIALIZE_FIELD(_205);
    PUTIT_SERIALIZE_FIELD(_206);
}
#undef PUTIT_SERIALIZE_FIELD
/* clang-format on */
