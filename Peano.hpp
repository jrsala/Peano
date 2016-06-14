#ifndef PEANO_H
#define PEANO_H


/**
 * Zero and Successor function
 */

struct Zero
{
    static constexpr int value = 0;
};

template<typename T>
struct Succ
{
    static constexpr int value = 1 + T::value;
};


#endif // PEANO_H
