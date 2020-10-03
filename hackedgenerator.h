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
};

}

#endif // HACKEDGENERATOR_H
