/* MIT License
Copyright (c) 2022 rdd6584 */

#ifndef CPP_EXTENDED_LIBRARY_COMBINATORICS_
#define CPP_EXTENDED_LIBRARY_COMBINATORICS_

#include <vector>

namespace cpp_extended_library {

class Combinatorics {
    typedef long long ll;

   private:
    std::vector<ll> factorial_, factorial_inverse_;
    ll modular_;

   public:
    Combinatorics(int modular) { modular_ = modular; }

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

    // Please, ensure you did InitializeFactorial(greater than, or equal to n);
    ll Factorial(int n) const { return factorial_[n]; }

    // Please, ensure you did InitializeFactorialWithInverse(greater than, or equal to n);
    ll FactorialInverse(int n) const { return factorial_inverse_[n]; }

    void InitializeFactorial(int n) {
        if (factorial_.size() >= n + 1) {
            return;
        }

        int previous_n = factorial_.size();
        factorial_.resize(n + 1);

        factorial_[0] = 1;
        for (int i = std::max(1, previous_n); i <= n; i++)
            factorial_[i] = factorial_[i - 1] * i % modular_;
    }
    void InitializeFactorialWithInverse(int n) {
        if (factorial_inverse_.size() >= n + 1) {
            return;
        }

        InitializeFactorial(n);

        int previous_n = factorial_inverse_.size();
        factorial_inverse_.resize(n + 1);

        factorial_inverse_[0] = 1;
        factorial_inverse_[n] = GetInverse(factorial_[n]);

        for (int i = n; i > previous_n; i--)
            factorial_inverse_[i - 1] = (factorial_inverse_[i] * i) % modular_;
    }

    // Please, ensure you did InitializeFactorialWithInverse(greater than, or equal to n);
    ll Permutation(int n, int r) const {
        return (r > n || r < 0) ? 0 : factorial_[n] * factorial_inverse_[n - r] % modular_;
    }

    // Please, ensure you did InitializeFactorialWithInverse(greater than, or equal to n);
    ll Combination(int n, int r) const {
        return (r > n || r < 0) ? 0 : factorial_[n] * factorial_inverse_[r] % modular_ * factorial_inverse_[n - r] % modular_;
    }

    // Please, ensure you did InitializeFactorialWithInverse(greater than, or equal to n + r - 1);
    ll CombinationWithRepetition(int n, int r) const {
        return Combination(n + r - 1, r);
    }

    // Please, ensure you did InitializeFactorialWithInverse(greater than, or equal to 2 * n);
    ll CatalanNumber(int n) {
        return Combination(2 * n, n) * GetInverse(n + 1) % modular_;
    }

    // Please, ensure you did InitializeFactorialWithInverse(greater than, or equal to n);
    ll DerangementNumber(int n) {
        ll result = 0;

        for (int k = 0, sign = 1; k <= n; k++, sign = -sign)
            result = (result + (factorial_[n] * sign * factorial_inverse_[k]) % modular_ + modular_) % modular_;
        return result;
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

#endif  // CPP_EXTENDED_LIBRARY_COMBINATORICS_
