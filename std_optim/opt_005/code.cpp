#include <utility>
#include <vector>
#include <iostream>
#include <chrono>
#include <iomanip>

#include "common/random.h"

using namespace std;

template <class T>
void swap_v1(T& a, T& b) {
    T tmp(a);   // we now have two copies of a
    a = b;      // we now have two copies of b (+ discarded a copy of a)
    b = tmp;    // we now have two copies of tmp (+ discarded a copy of b)
}

template <class T>
void swap_v2(T& a, T& b) {
    T tmp(std::move(a));
    a = std::move(b);   
    b = std::move(tmp);
}

int main() {
    int N = 100;

    using query = pair<vector<int>, vector<int>>;

    vector<query> queries;
    for(int cnt = 1; cnt <= 1e5; ++cnt) {
        vector<int> A;
        vector<int> B;
        for(auto i = 1; i <= N; ++i) {
            A.push_back(cm_random::IntRand(1, 1e9));
            B.push_back(cm_random::IntRand(1, 1e9));
        }
        queries.push_back({A, B});
    }
    
    auto benchmark_v1 = [&](string rem) {
        const auto start = std::chrono::high_resolution_clock::now();
        
        for(auto [u, v]: queries)
            swap_v1(u, v);

        const std::chrono::duration<long double> diff =
            std::chrono::high_resolution_clock::now() - start;
        
        cout << "Time: " << int(diff.count() * 1e9) << " nanosecs " << rem << '\n'; 
    };

    auto benchmark_v2 = [&](string rem) {
        const auto start = std::chrono::high_resolution_clock::now();
        
        for(auto [u, v]: queries)
            swap_v2(u, v); 

        const std::chrono::duration<long double> diff =
            std::chrono::high_resolution_clock::now() - start;
        
        cout << "Time: " << int(diff.count() * 1e9) << " nanosecs " << rem << '\n'; 
    };

    benchmark_v2("swap with std::move");
    benchmark_v1("normal swap");
    
    
}
