#include <iostream>
#include <assert.h>

#include "generator.h"
#include "hackedgenerator.h"

uint64_t constexpr TEST1 = 10000000;

uint64_t constexpr TEST2 = 9223372036854775807;
uint64_t constexpr TEST2_RESULT = 234862488;

auto constexpr FAILED_MSG = "FAILED\n";
auto constexpr PASSED_MSG = "PASSED\n";

int main(int /*argc*/, char** /*argv*/) {
    LCG::Generator generator;
    for (uint64_t i = 0; i < TEST1; ++i) {
        if (generator.next() != LCG::HackedGenerator::get(i)) {
            std::cout << FAILED_MSG;
            return 0;
        }
    }
    for (uint64_t i = 0; i < TEST1; ++i) {
        generator.next();
        generator.next();
    }
    if (generator.next() != LCG::HackedGenerator::get(TEST1 * 3)) {
        std::cout << FAILED_MSG;
        return 0;
    }
    if (LCG::HackedGenerator::get(TEST2) != TEST2_RESULT) {
        std::cout << FAILED_MSG;
        return 0;
    }
    std::cout << PASSED_MSG;
    return 0;
}
