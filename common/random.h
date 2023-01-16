#pragma once
#include <random>

namespace cm_random{

std::random_device device;
std::mt19937 generator(device());

int IntRand(int lo, int hi) {
    std::uniform_int_distribution<int> rd(lo, hi);
    return rd(generator);
}

} // cm_random namespace