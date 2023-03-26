#include <algorithm>
#include <chrono>
#include <execution>
#include <iostream>
#include <numeric>
#include <string_view>
#include <vector>
#include "common/random.h"

int main() {
    constexpr int N = 1e5;
    std::vector<int> a;
    for(int i = 1; i <= N; ++i)
        a.push_back(cm_random::IntRand(-100, 100));

    auto eval = [](auto func, std::string_view rem) {
        const auto start = std::chrono::high_resolution_clock::now();
        func();
        const auto end = std::chrono::high_resolution_clock::now();
        const std::chrono::duration<long double> diff  = end - start;
        std::cout << "Time: " << int(diff.count() * 1e9) << " nanosecs " << "( " << rem << " )" << '\n';
    };

    std::cout << "[+] std::reduce" << '\n';
    eval([&a]{ std::reduce(a.begin(), a.end()); }, "not parallelise");
    eval([&a]{ std::reduce(std::execution::par_unseq, a.begin(), a.end()); }, "parallelise and vectorise");
    eval([&a]{ std::reduce(std::execution::par, a.begin(), a.end()); }, "parallelise");
    
    std::cout << "[+] std::sort" << '\n';
    auto tmp = a;
    eval([&tmp]{ std::sort(tmp.begin(), tmp.end()); }, "not parallelise");
    tmp = a;
    eval([&tmp]{ std::sort(std::execution::par_unseq, tmp.begin(), tmp.end()); }, "parallelise and vectorise");
    tmp = a;
    eval([&tmp]{ std::sort(std::execution::par, tmp.begin(), tmp.end()); }, "parallelise");
}
