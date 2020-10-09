#include "hackedgenerator.h"

#include "constants.h"

namespace LCG {

uint64_t HackedGenerator::get(uint64_t n_) {
    ++n_;
    auto a_n_mod_m = HackedGenerator::a_n_mod_m(n_);

    return ((a_n_mod_m * INITIAL) % P + (frac_decomp(n_) % P) * C) % P;
}

uint64_t HackedGenerator::a_n_mod_m(uint64_t n) {
    if (!n)
        return 1;
    auto An = A;
    uint64_t result = 1;
    auto nn = n;
    while (n > 1)
    {
        if (n % 2) {
            result *= An;
            result %= P;
        }
        An = An * An % P;
        n /= 2;
    }
    result *= An;
    result %= P;
    return result;
}

uint64_t HackedGenerator::frac_decomp(uint64_t n) {
    if (n == 1 || !n)
        return n;
    return (((a_n_mod_m(n - n / 2) + 1) % P) * (frac_decomp(n / 2) % P) + (n % 2) * a_n_mod_m(n / 2));
}
}
