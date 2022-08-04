/* MIT License
Copyright (c) 2022 rdd6584 */

#ifndef CPP_EXTENDED_LIBRARY_MODULAR_ARITHMETIC_
#define CPP_EXTENDED_LIBRARY_MODULAR_ARITHMETIC_
#include <cstdio>

namespace cpp_extended_library {

// typename should be integer.
template <typename T = int, const T modular_ = (T)1e9 + 7>
class ModularArithmetic {
    typedef long long ll;

   public:
    struct ModularArithmeticNumber {
        friend class ModularArithmetic;

       private:
       public:
        T value;
        ModularArithmeticNumber(const ModularArithmeticNumber& modular_arithmetic_number) {
            *this = modular_arithmetic_number;
        }
        ModularArithmeticNumber(T integer_value) {
            value = integer_value % modular_ + (integer_value < 0) * modular_;
        }

        T operator()() const { return value; }
        bool operator<(const ModularArithmeticNumber& other) const { return value < other.value; }
        bool operator>(const ModularArithmeticNumber& other) const { return value > other.value; }
        bool operator==(const ModularArithmeticNumber& other) const { return value == other.value; }
        bool operator!=(const ModularArithmeticNumber& other) const { return value != other.value; }
        bool operator<=(const ModularArithmeticNumber& other) const { return value <= other.value; }
        bool operator>=(const ModularArithmeticNumber& other) const { return value >= other.value; }

        bool operator<(const T& other) const { return value < other; }
        bool operator>(const T& other) const { return value > other; }
        bool operator==(const T& other) const { return value == other; }
        bool operator!=(const T& other) const { return value != other; }
        bool operator<=(const T& other) const { return value <= other; }
        bool operator>=(const T& other) const { return value >= other; }

        ModularArithmeticNumber operator+(const ModularArithmeticNumber& other) const {
            return (value + other.value) - modular_ * (value + other.value >= modular_);
        }
        ModularArithmeticNumber operator-() const {
            return {-value + (value != 0) * modular_};
        }
        ModularArithmeticNumber operator-(const ModularArithmeticNumber& other) const {
            return {value - other.value + (value - other.value < 0) * modular_};
        }
        ModularArithmeticNumber operator*(const ModularArithmeticNumber& other) const {
            return {(ll)value * (ll)other.value % (ll)modular_};
        }
        ModularArithmeticNumber operator/(const ModularArithmeticNumber& other) const {
            return {(ll)value * (ll)ModularArithmetic::GetInverse(other.value, modular_) % (ll)modular_};
        }
        ModularArithmeticNumber operator+=(const ModularArithmeticNumber& other) {
            return *this = *this + other.value;
        }
        ModularArithmeticNumber operator-=(const ModularArithmeticNumber& other) {
            return *this = *this - other.value;
        }
        ModularArithmeticNumber operator*=(const ModularArithmeticNumber& other) {
            return *this = *this * other.value;
        }
        ModularArithmeticNumber operator/=(const ModularArithmeticNumber& other) {
            return *this = *this / other.value;
        }

        ModularArithmeticNumber operator+(const T& other) const {
            return (value + other) - modular_ * (value + other >= modular_);
        }
        ModularArithmeticNumber operator-(const T& other) const {
            return {value - other + (value - other < 0) * modular_};
        }
        ModularArithmeticNumber operator*(const T& other) const {
            return {(ll)value * (ll)other % (ll)modular_};
        }
        ModularArithmeticNumber operator/(const T& other) const {
            return {(ll)value * (ll)ModularArithmetic::GetInverse(other, modular_) % (ll)modular_};
        }
        ModularArithmeticNumber operator+=(const T& other) {
            return *this = *this + other;
        }
        ModularArithmeticNumber operator-=(const T& other) {
            return *this = *this - other;
        }
        ModularArithmeticNumber operator*=(const T& other) {
            return *this = *this * other;
        }
        ModularArithmeticNumber operator/=(const T& other) {
            return *this = *this / other;
        }
    };

    //////// ModularArithmetic ////////
    ModularArithmetic() {
        if (IsIntegerType())
            printf("integer_number should be (signed int or signed long long) !");
    }

    bool IsIntegerType() const {
        if (!std::is_same<T, int>::value && !std::is_same<T, ll>::value)
            return true;
        return false;
    }
    ModularArithmeticNumber CreateNumber(const ModularArithmeticNumber& modular_arithmetic_number) const {
        return ModularArithmeticNumber(modular_arithmetic_number);
    }

    ModularArithmeticNumber CreateNumber(T integer_value) const {
        return ModularArithmeticNumber(integer_value);
    }

    // Fix Me(ilwoo1.kwon): refactoring this. This functions are duplicated.
    ll FastPower(ll base, ll exponent) const {
        ll result = 1;
        while (exponent) {
            if (exponent & 1)
                result = result * base % modular_;
            base = base * base % modular_;
            exponent >>= 1;
        }
        return result;
    }
    ll GetInverse(const ll number) const {
        return FastPower(number, modular_ - 2);
    }

    // static
    static ll FastPower(ll base, ll exponent, const ll modular) {
        ll result = 1;
        while (exponent) {
            if (exponent & 1)
                result = result * base % modular;
            base = base * base % modular;
            exponent >>= 1;
        }
        return result;
    }
    static ll GetInverse(const ll number, const ll modular) {
        return FastPower(number, modular - 2, modular);
    }
};
}  // namespace cpp_extended_library

#endif  // CPP_EXTENDED_LIBRARY_MODULAR_ARITHMETIC_
