#include <iostream>
#include <utility>
#include <vector>
#include <chrono>
#include <functional>
using namespace std;

int main() {
    constexpr int N = 1e6;
    using KeyValue = pair<string, int>;

    auto benchmark_push_back = []() {
        vector<KeyValue> test;
        const auto start = std::chrono::high_resolution_clock::now();
        
        for(int x = 1; x <= N; ++x)
            test.push_back(KeyValue(to_string(x), x));

        const std::chrono::duration<long double> diff =
            std::chrono::high_resolution_clock::now() - start;
        
        cout << "Time: " << int(diff.count() * 1e9) << " nanosecs (push_back)" << '\n'; 
    };

    auto benchmark_emplace_back = []() {
        vector<KeyValue> test;
        const auto start = std::chrono::high_resolution_clock::now();
        
        for(int x = 1; x <= N; ++x)
            test.emplace_back(KeyValue(to_string(x), x));

        const std::chrono::duration<long double> diff =
            std::chrono::high_resolution_clock::now() - start;
        
        cout << "Time: " << int(diff.count() * 1e9) << " nanosecs (emplace_back)" << '\n'; 
    };

    for(int cnt = 1; cnt <= 5; ++cnt) {
        cout << "Run #" << cnt << ":\n";
        benchmark_push_back();
        benchmark_emplace_back();
    }
}
