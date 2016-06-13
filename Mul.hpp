/**
 * Multiplication
 */

template<typename A, typename B>
struct Mul_
{
};

template<typename A, typename B>
using Mul = typename Mul_<A, B>::result;

template<typename B>
struct Mul_<Zero, B>
{
    typedef Zero result;
};

template<typename A, typename B>
struct Mul_<Succ<A>, B>
{
    typedef Add<B, Mul<A, B>> result;
};
