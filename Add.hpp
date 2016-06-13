/**
 * Addition
 */

template<typename A, typename B>
struct Add_
{
};

template<typename A, typename B>
using Add = typename Add_<A, B>::result;

template<typename B>
struct Add_<Zero, B>
{
    typedef B result;
};

template<typename A, typename B>
struct Add_<Succ<A>, B>
{
    typedef Succ<Add<A, B> > result;
};