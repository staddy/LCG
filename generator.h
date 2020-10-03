#ifndef GENERATOR_H
#define GENERATOR_H

#include "constants.h"

namespace LCG {

class Generator {
public:
    Generator() = default;
    Generator(const Generator&) = default;
    Generator(Generator&&) = default;
    ~Generator() = default;
    Generator& operator=(const Generator&) = default;
    Generator& operator=(Generator&&) = default;
    uint64_t next();
private:
    uint64_t m_current{INITIAL};
};

}

#endif // GENERATOR_H
