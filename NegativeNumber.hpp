#include "Add.hpp"
#include "Mul.hpp"


/**
 * Minus
 */

template<typename A>
struct Minus_
{
    static constexpr int value = -A::value;
    typedef Minus_<A> result;
};

template<>
struct Minus_<Zero>
{
    typedef Zero result;
};

template<typename A>
struct Minus_<Minus_<A> >
{
    typedef A result;
};

template<typename A>
using Minus = typename Minus_<A>::result;


/**
 * Addition with negative integers
 */

template<typename A, typename B>
struct Add_<Minus_<A>, Minus_<B> >
{
    typedef Minus<Add<A, B> > result;
};

template<typename A, typename B>
struct Add_<Minus_<A>, B>
{
    typedef Add<B, Minus<A> > result;
};


/**
 * Multiplication with negative integers
 */

template<typename A, typename B>
struct Mul_<Minus_<A>, Minus_<B> >
{
    typedef Mul<A, B> result;
};

template<typename A, typename B>
struct Mul_<Minus_<A>, B>
{
    typedef Minus<Mul<A, B> > result;
};
