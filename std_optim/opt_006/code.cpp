#include <iostream>

// a constexpr basic product function
constexpr int product(int x, int y) {
	return x * y;
}

// a consteval basic plus function
consteval int plus(int x, int y) {
    return x + y;
}

int main() {
    constexpr int y = 2;
    int x; std::cin >> x;
    int res0 = plus(y, 4);      // OK
	int res1 = product(x, 2);   // OK, will compile at run time
    // int res2 = plus(x, 4);   // compile error: x is not a const expression
}
