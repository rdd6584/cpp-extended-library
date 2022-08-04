#include <assert.h>
#include <cstdio>
#include <string>
#include "combinatorics.hpp"
#include "fraction.hpp"
#include "modular_arithmetic.hpp"

typedef cpp_extended_library::Fraction Fraction;
typedef cpp_extended_library::Combinatorics Combinatorics;
typedef cpp_extended_library::ModularArithmetic<int> ModularArithmetic;

void FractionTest() {
    Fraction af, bf;
    int a = 1, b = 5, c = -3, d = 2;

    af = {a, b};
    bf = {c, d};

    assert((af + bf).String() == "-13/10");
    assert((-af).String() == "-1/5");
    assert((af - bf).String() == "17/10");
    assert((af * bf).String() == "-3/10");
    assert((af / bf).String() == "-2/15");
    assert((af > bf) == true);
    assert((af < bf) == false);
    assert((af == bf) == false);

    assert((af != bf) == true);
    assert((af >= bf) == true);
    assert((af <= bf) == false);
    af -= bf;
    assert(af.String() == "17/10");
    assert(af.IsInfinity() == false);
    assert(Fraction(5, 0).IsInfinity() == true);

    printf("Passed FractionTest !\n");
}

void CombinatoricsTest() {
    Combinatorics combinatorics(1e9 + 7);
    combinatorics.InitializeFactorialWithInverse(1001);

    assert(combinatorics.Factorial(0) == 1);
    assert(combinatorics.GetInverse(1) == 1);

    assert(combinatorics.FastPower(10, 3) == 1000);

    assert(combinatorics.Factorial(10) == 3628800);
    assert(combinatorics.Combination(20, 10) == 184756);
    assert(combinatorics.CombinationWithRepetition(20, 10) == 20030010);

    assert(combinatorics.CatalanNumber(0) == 1);
    assert(combinatorics.CatalanNumber(1) == 1);
    assert(combinatorics.CatalanNumber(2) == 2);
    assert(combinatorics.CatalanNumber(3) == 5);
    assert(combinatorics.CatalanNumber(4) == 14);

    assert(combinatorics.DerangementNumber(1) == 0);
    assert(combinatorics.DerangementNumber(2) == 1);
    assert(combinatorics.DerangementNumber(5) == 44);
    assert(combinatorics.DerangementNumber(6) == 265);
    assert(combinatorics.DerangementNumber(7) == 1854);

    assert(combinatorics.Permutation(5, 2) == 20);
    printf("Passed CombinatoricsTest !\n");
}

void ModularArithmeticTest() {
    cpp_extended_library::ModularArithmetic<int, 11> modular_arithmetic;
    assert(modular_arithmetic.FastPower(2, 5) == 10);

    auto tmp = modular_arithmetic.CreateNumber(10);
    auto tt = tmp;

    tt = 5;
    assert(tt == 5);
    // assert(5 == tt);

    tt += 3;
    assert(tt == 8);
    assert(tt + 8 == 5);

    tt = tt + 8;
    assert(tt == 5);
    assert(tt - 10 == 6);
    assert(tt * 5 == 3);

    assert(tt * 5 + 3 == 6);
    assert((tmp = 4) * (tt / (tt * 2)) == 2);
    assert(tmp == 4);

    assert(modular_arithmetic.CreateNumber(4) == tmp);
    assert(modular_arithmetic.CreateNumber(50)());

    printf("Passed ModularArithmeticTest !\n");
}

int main() {
    FractionTest();
    CombinatoricsTest();
    ModularArithmeticTest();
}
