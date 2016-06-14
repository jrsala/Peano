#ifndef LIST_H
#define LIST_H


/**
 * Lists
 */
struct EmptyList;

template<typename Head, typename Tail>
struct Cons;

template<typename List>
struct Head_;

template<>
template<typename H, typename T>
struct Head_<Cons<H, T> >
{
    typedef H result;
};

template<typename List>
using Head = typename Head_<List>::result;

template<typename List>
struct Tail_;

template<>
template<typename H, typename T>
struct Tail_<Cons<H, T> >
{
    typedef T result;
};

template<typename List>
using Tail = typename Tail_<List>::result;


#endif // LIST_H
