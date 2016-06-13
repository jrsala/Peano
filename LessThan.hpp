#include <type_traits>


/**
 * Inequality comparison
 */

template<typename A, typename B>
struct LessThan
{
};

template<typename B>
struct LessThan<Zero, B> : public std::true_type
{
};

template<typename A>
struct LessThan<Succ<A>, Zero> : public std::false_type
{
};

template<typename A, typename B>
struct LessThan<Succ<A>, Succ<B> > : public LessThan<A, B>
{
};
