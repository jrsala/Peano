#include <type_traits>


/**
 * Equality comparison
 */

template<typename A, typename B>
struct Equals
{
};

template<>
struct Equals<Zero, Zero> : public std::true_type
{
};

template<typename B>
struct Equals<Zero, Succ<B> > : public std::false_type
{
};

template<typename A>
struct Equals<Succ<A>, Zero> : public std::false_type
{
};

template<typename A, typename B>
struct Equals<Succ<A>, Succ<B> > : public Equals<A, B>
{
};
