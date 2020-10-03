#include "generator.h"

namespace LCG {

uint64_t Generator::next() {
    m_current = (m_current * A + C) % P;
    return m_current;
}

}
