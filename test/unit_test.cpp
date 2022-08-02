#include <assert.h>
#include <cstdio>
#include "combinatorics.hpp"
#include "fraction.hpp"
typedef cpp_extended_library::Fraction Fraction;
typedef cpp_extended_library::Combinatorics Combinatorics;

void FractionTest() {
    Fraction af, bf;
    int a = 1, b = 5, c = -3, d = 2;

    af = {a, b};
    bf = {c, d};

    assert((af + bf).GetString() == "-13/10");
    assert((af - bf).GetString() == "17/10");
    assert((af * bf).GetString() == "-3/10");
    assert((af / bf).GetString() == "-2/15");
    assert((af > bf) == true);
    assert((af < bf) == false);
    assert((af == bf) == false);
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
}

int main() {
    FractionTest();
    printf("Passed FractionTest !\n");

    CombinatoricsTest();
    printf("Passed CombinatoricsTest !");
}
