#include <iostream>

template<typename T>
void log(const T& x)
{
    std::cout << x << std::endl;
}


#include "Peano.hpp"
#include "Add.hpp"
#include "Mul.hpp"
#include "NegativeNumber.hpp"
#include "List.hpp"
#include "Fold.hpp"

int main()
{
    typedef Succ<Zero> One;
    typedef Succ<One> Two;
    typedef Succ<Two> Three;
    typedef Succ<Three> Four;
    typedef Succ<Four> Five;
    typedef Succ<Five> Six;
    typedef Succ<Six> Seven;
    typedef Succ<Seven> Eight;
    typedef Succ<Eight> Nine;

    log("Succ:\n");

    log("s(s(0)): " + std::to_string(Two::value));


    log("\n\nAdd:\n");

    log("4 + 4: " + std::to_string(Add<Four, Four>::value));


    log("\n\nMul:\n");

    log("4 * 4: " + std::to_string(Mul<Four, Four>::value));


    log("\n\nEquals:\n");

    log("4 == 4: " + std::to_string(Equals<Four, Four>::value));
    log("2 == 7: " + std::to_string(Equals<Two, Seven>::value));
    log("7 == 2: " + std::to_string(Equals<Seven, Two>::value));


    log("\n\nLessThan:\n");

    log("0 <= 0: " + std::to_string(LessThan<Zero, Zero>::value));
    log("0 <= 2: " + std::to_string(LessThan<Zero, Two>::value));
    log("2 <= 0: " + std::to_string(LessThan<Two, Zero>::value));
    log("2 <= 4: " + std::to_string(LessThan<Two, Four>::value));
    log("4 <= 2: " + std::to_string(LessThan<Four, Two>::value));


    log("\n\nMinus:\n");

    log("-0: " + std::to_string(Minus<Zero>::value));
    log("-1: " + std::to_string(Minus<Succ<Zero> >::value));
    log("-(-2): " + std::to_string(Minus<Minus<Two> >::value));
    log("2 + (-2): " + std::to_string(Add<Two, Minus<Two> >::value));
    log("2 + (-4): " + std::to_string(Add<Two, Minus<Four> >::value));
    log("(-2) + 4: " + std::to_string(Add<Minus<Two>, Four>::value));
    log("(-4) + 2: " + std::to_string(Add<Minus<Four>, Two>::value));
    log("(-4) + (-2): " + std::to_string(Add<Minus<Four>, Minus<Two> >::value));
    log("2 * (-4): " + std::to_string(Mul<Two, Minus<Four> >::value));
    log("(-2) * 4: " + std::to_string(Mul<Minus<Two>, Four>::value));
    log("(-2) * (-4): " + std::to_string(Mul<Minus<Two>, Minus<Four> >::value));
    log("((-((-7) + 6))*(-3))*(5 * (-0) + (-2)) expected result 6: " + std::to_string(
        Mul<
            Mul<
                Minus<
                    Add<
                        Minus<Seven>,
                        Six
                    >
                >,
                Minus<Three>
            >,
            Add<
                Mul<
                    Five,
                    Minus<Zero>
                >,
                Minus<Two>
            >
        >::value));


    log("\n\nLists:\n");

    typedef Cons<One, Cons<Two, Cons<Three, EmptyList> > > OneTwoThree;
    log("hd 1::2::3 : " + std::to_string(Head<OneTwoThree>::value));
    log("fold 1::2::3 0 +: " + std::to_string(Fold<OneTwoThree, Zero, Add>::value));

    log("\n");
}
