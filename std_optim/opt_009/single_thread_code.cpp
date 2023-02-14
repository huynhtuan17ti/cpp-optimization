
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

void vectorAdd(const vector<int>& A, const vector<int>& B) {
    int n = (int)A.size();
    vector<int> res(n);
    for(int i = 0; i < n; ++i)
        res[i] = A[i] + B[i];
}

int main() {
    constexpr int NUM_TESTS = 100;
    constexpr int VECTOR_SZ = 100000;

    vector<int> A(VECTOR_SZ);
    vector<int> B(VECTOR_SZ);

    for(int i = 0; i < VECTOR_SZ; ++i) {
        A[i] = i;
        B[i] = i + VECTOR_SZ;
    }
    const auto start = std::chrono::high_resolution_clock::now();
    for(int cnt = 1; cnt <= NUM_TESTS; ++cnt) {
        vectorAdd(A, B);
    }
    
    const std::chrono::duration<long double> diff =
            std::chrono::high_resolution_clock::now() - start;

    cout << "Time: " << int(diff.count() * 1e9)
                  << " nanosecs (single thread)" << '\n';
}
