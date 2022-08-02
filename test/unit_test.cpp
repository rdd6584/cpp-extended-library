#include <cstdio>
#include "fraction.hpp"
typedef cpp_extended_stl::Fraction Fraction;

int main() {
    Fraction af, bf;
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    af = {a, b};
    bf = {c, d};

    printf("%s\n", (af + bf).GetString().c_str());
    printf("%s\n", (af - bf).GetString().c_str());
    printf("%s\n", (af * bf).GetString().c_str());
    printf("%s\n", (af / bf).GetString().c_str());
    printf("%d %d\n", af > bf, af < bf);
    printf("%d\n", af == bf);
}
