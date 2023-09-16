#include <algorithm>
#include <bitset>
#include <chrono>
#include <iostream>
#include <vector>
#include "random.h"

#include <benchmark/benchmark.h>

constexpr int seed = 9999;
constexpr int N = 1e4;
constexpr int MAX_VAL = N * 100;

static std::vector<int> A;

void Init() {
  for (int i = 0; i < N; ++i)
    A.push_back(cm_random::IntRand(1, 100, seed));
}

inline int native_sol() {
  std::vector<int> dp(MAX_VAL + 1);
  dp[0] = 1;
  for (int u : A)
    for (int j = MAX_VAL; j >= u; --j)
      dp[j] |= dp[j - u];
  return std::count(dp.begin(), dp.end(), 1);
}

inline int optim_sol() {
  std::bitset<MAX_VAL> dp;
  dp.set(0);
  for (int u : A)
    dp |= dp << u;
  return dp.count();
}

static void BM_normal_dp(benchmark::State& state) {
  Init();
  for (auto _ : state) {
    auto result = native_sol();
    benchmark::DoNotOptimize(result);
  }
}

static void BM_biset_dp(benchmark::State& state) {
  Init();
  for (auto _ : state) {
    auto result = optim_sol();
    benchmark::DoNotOptimize(result);
  }
}

BENCHMARK(BM_normal_dp);
BENCHMARK(BM_biset_dp);

BENCHMARK_MAIN();
