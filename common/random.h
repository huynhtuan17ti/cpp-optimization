#pragma once
#include <random>

namespace cm_random {

inline int IntRand(int lo, int hi, int seed = 2023) {
  std::seed_seq seed_{seed};
  std::default_random_engine eng{seed_};
  std::uniform_int_distribution<int> rd(lo, hi);
  return rd(eng);
}

}  // namespace cm_random
