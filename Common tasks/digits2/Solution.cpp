//
// Created by User on 04-Mar-21.
//

#include "Solution.h"
int64_t Solution::bin_pow(int64_t base, int p) {
    if (p == 1) {
        return base;
    }

    if (p % 2 == 0) {
        int64_t t = bin_pow(base, p / 2);
        return t * t % MOD;
    } else {
        return bin_pow(base, p - 1) * base % MOD;
    }
}

Solution::Solution() {

    std::cin >> lines >> digits;

    int max = std::max(digits, lines - digits);
    int min = std::min(digits, lines - digits);
    int64_t a = 1;
    int64_t b = 1;
    for (int i = 1; i < min + 1; i++) {
        a *= max + i;
        a %= MOD;
        b *= i;
        b %= MOD;
    }
    std::cout << a * bin_pow(b, MOD - 2) % MOD << std::endl;
}