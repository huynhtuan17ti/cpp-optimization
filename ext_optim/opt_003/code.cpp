#include <benchmark/benchmark.h>
#include <chrono>
#include <functional>
#include <iostream>
#include <vector>

#include "common/random.h"

using namespace std;
constexpr int N = 5e3;
constexpr int seed = 2810;

int a[N][N];

inline void init() {
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      a[i][j] = cm_random::IntRand(1, 1e8, seed);
}

static void BM_without_cache_conherency(benchmark::State& state) {
  init();
  for (auto _ : state) {
    int cnt = 0;
    for (int j = 0; j < N; j++)
      for (int i = 0; i < N; i++)
        cnt += (a[i][j] % 2);
    benchmark::DoNotOptimize(cnt);
  }
}

static void BM_cache_conherency(benchmark::State& state) {
  init();
  for (auto _ : state) {
    int cnt = 0;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        cnt += (a[i][j] % 2);
    benchmark::DoNotOptimize(cnt);
  }
}

BENCHMARK(BM_cache_conherency);
BENCHMARK(BM_without_cache_conherency);

BENCHMARK_MAIN();
