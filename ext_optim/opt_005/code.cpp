#include <algorithm>
#include <vector>
#include <iostream>
#include <immintrin.h>
#include <chrono>
#include <string>
#include <functional>

#include "random.h"

using Vector = std::vector<float>;

Vector regularAdd(const Vector& a, const Vector& b) {
	Vector result(a.size());
	for(int i = 0; i < (int)result.size(); ++i)
		result[i] = a[i] + b[i];
	return result;
}

Vector simdAdd(const Vector& a, const Vector& b) {
	Vector result(a.size());
	constexpr auto FLOATS_IN_AVX_REGISTER = 8u;
	const auto vectorizableSamples = ((int)a.size() / FLOATS_IN_AVX_REGISTER) * FLOATS_IN_AVX_REGISTER;

	auto i = 0u;
	for(; i < vectorizableSamples; i += FLOATS_IN_AVX_REGISTER) {
		auto aRegister = _mm256_loadu_ps(a.data() + i);
		auto bRegister = _mm256_loadu_ps(b.data() + i);

		auto sum = _mm256_add_ps(aRegister, bRegister);
		_mm256_storeu_ps(result.data() + i, sum);
	}
	for(; i < result.size(); ++i)
		result[i] = a[i] + b[i];
	return result;
}

int main() {
	constexpr int N = 1e6;
	Vector A(N), B(N);
	for(int i = 0; i < N; ++i) {
		A[i] = cm_random::IntRand(1, 1e6);
		B[i] = cm_random::IntRand(1, 1e6);
	}

    auto benchmark = [&](std::function<Vector(const Vector&, const Vector&)> func, std::string rem) {
        const auto start = std::chrono::high_resolution_clock::now();
        auto result = func(A, B);
        const std::chrono::duration<long double> diff =
            std::chrono::high_resolution_clock::now() - start;
		std::cout << "Time: " << int(diff.count() * 1e9)
                  << " nanosecs " << rem << '\n'; 
    };

	benchmark(regularAdd, "(regular vector adding operation)");
	benchmark(simdAdd, "(SIMD vector adding operation)");
}
