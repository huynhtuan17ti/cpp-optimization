#include <iostream>
#include <vector>
#include <chrono>
#include <functional>

#include "random.h"

using namespace std;
const int N = 5e3;

int a[N][N];

inline void init() {
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            a[i][j] = cm_random::IntRand(1, 1e8);
}

inline void iterationV1() {
    int cnt = 0;
    for(int j = 0; j < N; j++)
        for(int i = 0; i < N; i++)
            cnt += (a[i][j] % 2);
    cout << cnt << '\n';
}

inline void iterationV2() {
    int cnt = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cnt += (a[i][j] % 2);
    cout << cnt << '\n';
}

int main() {
    init();
    auto benchmark = [&](function<void()> func, string rem) {
        const auto start = chrono::high_resolution_clock::now();
        const chrono::duration<long double> diff =
                chrono::high_resolution_clock::now() - start;
        func();
        cout << "Time: " << diff.count() * 1e9
                  << " nanosecs " << rem << '\n'; 
    };

    benchmark(iterationV1, "(without cache coherency)");
    benchmark(iterationV2, "(with cache coherency)");
}