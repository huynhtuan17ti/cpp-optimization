#include <bitset>
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include "random.h"

int main() {
    std::vector<int> a;
    constexpr int N = 1e4;
    for(int i = 0; i < N; ++i)
        a.push_back(cm_random::IntRand(1, 100));
    constexpr int MAX_VAL = N * 100;

    auto native_sol = [&a]() {
        std::vector<int> dp(MAX_VAL + 1);
        dp[0] = 1;
        for(int u: a)
            for(int j = MAX_VAL; j >= u; --j)
                dp[j] |= dp[j - u];
        return std::count(dp.begin(), dp.end(), 1);
    };
    
    auto optim_sol = [&a]() {
        std::bitset<MAX_VAL> dp;
        dp.set(0);
        for(int u: a)
            dp |= dp << u;
        return dp.count();
    };
    
    auto benchmark = [&](auto func, std::string_view rem) {
        const auto start = std::chrono::high_resolution_clock::now();
        func();
        const std::chrono::duration<long double> diff =
            std::chrono::high_resolution_clock::now() - start;
        std::cout << "Time: " << int(diff.count() * 1000)
                  << " millisecs " << rem << '\n';  
    };

    benchmark(native_sol, "(native sol)");
    benchmark(optim_sol, "(bitset sol)");
}
