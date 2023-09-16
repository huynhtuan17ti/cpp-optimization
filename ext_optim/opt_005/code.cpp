#include <benchmark/benchmark.h>
#include <immintrin.h>
#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

#include "common/random.h"

constexpr int N = 1e6;
using Vector = std::vector<float>;
static Vector A(N), B(N);

void Init(int seed = 2023) {
  for (int i = 0; i < N; ++i) {
    A[i] = cm_random::IntRand(1, 1e6, seed);
    B[i] = cm_random::IntRand(1, 1e6, seed);
  }
}

Vector regularAdd(const Vector& a, const Vector& b) {
  Vector result(a.size());
  for (int i = 0; i < (int)result.size(); ++i)
    result[i] = a[i] + b[i];
  return result;
}

Vector simdAdd(const Vector& a, const Vector& b) {
  Vector result(a.size());
  constexpr auto FLOATS_IN_AVX_REGISTER = 8u;
  const auto vectorizableSamples =
      ((int)a.size() / FLOATS_IN_AVX_REGISTER) * FLOATS_IN_AVX_REGISTER;

  auto i = 0u;
  for (; i < vectorizableSamples; i += FLOATS_IN_AVX_REGISTER) {
    auto aRegister = _mm256_loadu_ps(a.data() + i);
    auto bRegister = _mm256_loadu_ps(b.data() + i);

    auto sum = _mm256_add_ps(aRegister, bRegister);
    _mm256_storeu_ps(result.data() + i, sum);
  }
  for (; i < result.size(); ++i)
    result[i] = a[i] + b[i];
  return result;
}

static void BM_regular_vector_add(benchmark::State& state) {
  Init();
  for (auto _ : state) {
    auto result = regularAdd(A, B);
    benchmark::DoNotOptimize(result);
  }
}

static void BM_simd_vector_add(benchmark::State& state) {
  Init();
  for (auto _ : state) {
    auto result = simdAdd(A, B);
    benchmark::DoNotOptimize(result);
  }
}

BENCHMARK(BM_regular_vector_add);
BENCHMARK(BM_simd_vector_add);

BENCHMARK_MAIN();
