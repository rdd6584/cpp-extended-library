#ifndef CPP_EXTENDED_STL_FRACTION_
#define CPP_EXTENDED_STL_FRACTION_

#include <numeric>
#include <string>
#include <vector>

namespace cpp_extended_stl {

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
    bool operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }
    bool operator>(const Fraction& other) const {
        return numerator * other.denominator > other.numerator * denominator;
    }
    bool operator==(const Fraction& other) const {
        const Fraction& me = GetIrreducible();
        const Fraction& you = other.GetIrreducible();

        return me.numerator == you.numerator &&
               me.denominator == you.denominator;
    }
    Fraction operator+(const Fraction& other) const {
        Fraction result(
            numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator);
        ToIrreducible(result);
        return result;
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
    std::string GetString() const {
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }
};
}  // namespace cpp_extended_stl

#endif  // CPP_EXTENDED_STL_FRACTION_
