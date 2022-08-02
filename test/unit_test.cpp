#include <cstdio>
#include "fraction.hpp"
typedef cpp_extended_stl::Fraction Fraction;

int main() {
    Fraction af, bf;
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    af = {a, b};
    bf = {c, d};

    printf("%s\n", (af + bf).ToString().c_str());
    printf("%s\n", (af - bf).ToString().c_str());
    printf("%s\n", (af * bf).ToString().c_str());
    printf("%s\n", (af / bf).ToString().c_str());
}
