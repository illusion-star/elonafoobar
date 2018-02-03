#pragma once
#include <algorithm>
#include <iterator>


namespace elona::range
{


template <typename R, typename P>
auto count_if(const R& range, P predicate)
{
    using std::begin, std::end;
    return std::count_if(begin(range), end(range), predicate);
}



template <typename R>
auto distance(const R& range)
{
    using std::begin, std::end;
    return std::distance(begin(range), end(range));
}



template <typename R, typename F>
bool all_of(const R& range, F predicate)
{
    using std::begin, std::end;
    return std::all_of(begin(range), end(range), predicate);
}



template <typename R, typename F>
bool any_of(const R& range, F predicate)
{
    using std::begin, std::end;
    return std::any_of(begin(range), end(range), predicate);
}



template <typename R, typename I, typename F>
auto transform(const R& src, I dst, F func)
{
    using std::begin, std::end;
    return std::transform(begin(src), end(src), dst, func);
}



template <typename R, typename I, typename F>
auto transform(R&& src, I dst, F func)
{
    using std::begin, std::end;
    return std::transform(begin(src), end(src), dst, func);
}



template <typename R, typename F>
auto for_each(const R& range, F func)
{
    using std::begin, std::end;
    return std::for_each(begin(range), end(range), func);
}



template <typename R, typename T>
auto find(const R& range, const T& value)
{
    using std::begin, std::end;
    return std::find(begin(range), end(range), value);
}



template <typename R, typename F>
auto find_if(const R& range, F predicate)
{
    using std::begin, std::end;
    return std::find_if(begin(range), end(range), predicate);
}



template <typename R, typename T>
auto fill(R&& range, const T& value)
{
    using std::begin, std::end;
    return std::fill(begin(range), end(range), value);
}



template <typename R1, typename R2>
bool equal(const R1& range1, const R2& range2)
{
    using std::begin, std::end;
    return std::equal(begin(range1), end(range1), begin(range2));
}



} // namespace elona::range
