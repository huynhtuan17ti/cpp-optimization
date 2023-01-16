/*
* Given 10^6 queries, each queries is an interger number.
* Calculate X - Y, where
* X = The number of numbers that are not multiples of 4.
* Y = The number of numbers that are multiples of 4.
*/
#include <chrono>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <functional>

#include "random.h"

using namespace std;

inline int calcFunc(vector<int> &queries) {
    int cnt = 0;
    for(int x: queries)
        if(x%4 > 0) cnt++;
        else cnt--;
    return cnt;
}

inline int optimCalcFunc(vector<int> &queries) {
    int cnt = 0;
    for(int x: queries)
        if(x%4 > 0) [[unlikely]] 
            cnt++;
        else cnt--;
    return cnt;
}

int main() {
    vector<int> queries;
    for(int iter = 1; iter <= 1e6; ++iter) {
        queries.push_back(cm_random::IntRand(1, 1e9));
    }

    auto benchmark = [&](function<int(vector<int>&)> func, string rem) {
        const auto start = std::chrono::high_resolution_clock::now();
        const std::chrono::duration<long double> diff =
            std::chrono::high_resolution_clock::now() - start;
        int result = func(queries);
        cout << "Result: " << result << '\n';
        cout << "Time: " << fixed << setprecision(10) << diff.count() * 1e9
                  << " nanosecs " << rem << '\n'; 
    };

    benchmark(calcFunc, "(without attributes)");
    benchmark(optimCalcFunc, "(with attributes)");
}