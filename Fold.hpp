#ifndef FOLD_H
#define FOLD_H


#include "List.hpp"


/**
 * List algorithms
 */

template<typename List, typename Acc, template<typename, typename> class F>
struct Fold_
{
    typedef typename Fold_<Tail<List>, F<Acc, Head<List> >, F>::result result;
};

template<typename List, typename Acc, template<typename, typename> class F>
using Fold = typename Fold_<List, Acc, F>::result;

template<typename Acc, template<typename, typename> class F>
struct Fold_<EmptyList, Acc, F>
{
    typedef Acc result;
};


#endif // FOLD_H
