#include <string_view>
#include <string>
#include <chrono>
#include <iostream>
#include "random.h"

inline void string_get_substr(std::string s) {
    std::string substr = s.substr(1000, 10000);
}

inline void string_view_get_substr(std::string_view s) {
    std::string_view substr = s.substr(1000, 10000);
}

int main() {
    constexpr int N = 1e5;
    std::string s;

    auto benchmark = [&](auto&& func, std::string rem) {
        const auto start = std::chrono::high_resolution_clock::now();
        func(s);
        const std::chrono::duration<long double> diff =
            std::chrono::high_resolution_clock::now() - start;
        std::cout << "Time: " << int(diff.count() * 1e9)
                  << " nanosecs " << rem << '\n'; 
    };

    for(int cnt = 1; cnt <= 5; ++cnt) {
        std::cout << "RUN #" << cnt << '\n';
        s = "";
        for(int i = 0; i < N; ++i)
            s += (char)cm_random::IntRand((int)'a', (int)'z');
        
        benchmark(string_get_substr, "(string)");
        benchmark(string_view_get_substr, "(string_view)");
        std::cout << "---------------" << '\n';
    }
}
