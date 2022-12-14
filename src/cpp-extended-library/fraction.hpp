/* MIT License
Copyright (c) 2022 rdd6584 */

#ifndef CPP_EXTENDED_LIBRARY_FRACTION_
#define CPP_EXTENDED_LIBRARY_FRACTION_

#include <numeric>
#include <string>
#include <vector>

namespace cpp_extended_library {

class Fraction {
    typedef long long ll;

   public:
    ll numerator, denominator;
    Fraction() { Fraction(0, 1); }
    Fraction(const ll& value) { Fraction(value, 1); }

    Fraction(const std::pair<ll, ll>& value) {
        numerator = value.first, denominator = value.second;
    }
    Fraction(const ll& numerator, const ll& denominator) {
        if (denominator < 0) {
            this->numerator = -numerator;
            this->denominator = -denominator;
        } else {
            this->numerator = numerator;
            this->denominator = denominator;
        }
    }
    void ToIrreducible() {
        const ll& gcd_value = std::gcd(numerator, denominator);
        numerator /= gcd_value;
        denominator /= gcd_value;
    }
    Fraction GetIrreducible() const {
        const ll& gcd_value = std::gcd(numerator, denominator);
        return Fraction(numerator / gcd_value, denominator / gcd_value);
    }

    bool operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }
    bool operator>(const Fraction& other) const {
        return numerator * other.denominator > other.numerator * denominator;
    }
    bool operator==(Fraction other) const {
        const Fraction& me = GetIrreducible();
        other.ToIrreducible();

        return me.numerator == other.numerator &&
               me.denominator == other.denominator;
    }
    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }
    bool operator<=(const Fraction& other) const {
        return !(*this > other);
    }
    bool operator>=(const Fraction& other) const {
        return !(*this < other);
    }

    Fraction operator+(const Fraction& other) const {
        Fraction result(
            numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator);
        ToIrreducible(result);
        return result;
    }
    Fraction operator-() const {
        return Fraction(-numerator, denominator);
    }
    Fraction operator-(const Fraction& other) const {
        Fraction result(
            numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator);
        ToIrreducible(result);
        return result;
    }
    Fraction operator*(const Fraction& other) const {
        Fraction result(numerator * other.numerator,
                        denominator * other.denominator);
        ToIrreducible(result);
        return result;
    }
    Fraction operator/(const Fraction& other) const {
        Fraction result(numerator * other.denominator,
                        denominator * other.numerator);
        ToIrreducible(result);
        return result;
    }

    Fraction operator+=(const Fraction& other) {
        return *this = *this + other;
    }
    Fraction operator-=(const Fraction& other) {
        return *this = *this - other;
    }
    Fraction operator*=(const Fraction& other) {
        return *this = *this * other;
    }
    Fraction operator/=(const Fraction& other) {
        return *this = *this / other;
    }

    std::string String() const {
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }
    bool IsInfinity() const {
        return denominator == 0;
    }

    // static
    static void ToIrreducible(Fraction& value) {
        const ll& gcd_value = std::gcd(value.numerator, value.denominator);
        value.numerator /= gcd_value;
        value.denominator /= gcd_value;
    }
    static Fraction GetIrreducible(const Fraction& value) {
        const ll& gcd_value = std::gcd(value.numerator, value.denominator);
        return Fraction(value.numerator / gcd_value,
                        value.denominator / gcd_value);
    }
};
}  // namespace cpp_extended_library

#endif  // CPP_EXTENDED_LIBRARY_FRACTION_
