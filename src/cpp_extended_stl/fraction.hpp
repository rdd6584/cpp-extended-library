#ifndef CPP_EXTENDED_STL_FRACTION_
#define CPP_EXTENDED_STL_FRACTION_

#include <numeric>
#include <string>
#include <vector>

namespace cpp_extended_stl {

class Fraction {
   public:
    long long numerator, denominator;
    Fraction() { Fraction(0, 1); }
    Fraction(const long long& value) { Fraction(value, 1); }
    Fraction(const std::pair<long long, long long>& value) {
        numerator = value.first, denominator = value.second;
    }
    Fraction(const long long& numerator, const long long& denominator) {
        if (denominator < 0) {
            this->numerator = -numerator;
            this->denominator = -denominator;
        } else {
            this->numerator = numerator;
            this->denominator = denominator;
        }
    }
    void ToIrreducible() {
        const long long& gcd_value = std::gcd(numerator, denominator);
        numerator /= gcd_value;
        denominator /= gcd_value;
    }
    static void ToIrreducible(Fraction& value) {
        const long long& gcd_value =
            std::gcd(value.numerator, value.denominator);
        value.numerator /= gcd_value;
        value.denominator /= gcd_value;
    }
    Fraction GetIrreducible(const Fraction& value) {
        const long long& gcd_value =
            std::gcd(value.numerator, value.denominator);
        return Fraction(value.numerator / gcd_value,
                        value.denominator / gcd_value);
    }
    bool operator<(const Fraction& other) {
        return numerator * other.denominator < other.numerator * denominator;
    }
    bool operator>(const Fraction& other) {
        return numerator * other.denominator > other.numerator * denominator;
    }
    bool operator==(const Fraction& other) {
        return GetIrreducible(*this) == GetIrreducible(other);
    }
    Fraction operator+(const Fraction& other) {
        Fraction result(
            numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator);
        ToIrreducible(result);
        return result;
    }
    Fraction operator-(const Fraction& other) {
        Fraction result(
            numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator);
        ToIrreducible(result);
        return result;
    }
    Fraction operator*(const Fraction& other) {
        Fraction result(numerator * other.numerator,
                        denominator * other.denominator);
        ToIrreducible(result);
        return result;
    }
    Fraction operator/(const Fraction& other) {
        Fraction result(numerator * other.denominator,
                        denominator * other.numerator);
        ToIrreducible(result);
        return result;
    }
    std::string ToString() {
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }
};
}  // namespace cpp_extended_stl

#endif  // CPP_EXTENDED_STL_FRACTION_
