#ifndef HACKEDGENERATOR_H
#define HACKEDGENERATOR_H

#include <cstdint>

namespace LCG {

class HackedGenerator {
public:
    HackedGenerator() = delete;
    HackedGenerator(const HackedGenerator&) = delete;
    HackedGenerator(HackedGenerator&&) = delete;
    static uint64_t get(uint64_t n_);

private:
    static uint64_t a_n_mod_m(uint64_t n);
    static uint64_t frac_decomp(uint64_t n);
};

}

#endif // HACKEDGENERATOR_H
