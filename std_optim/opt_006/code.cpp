#include <iostream>

constexpr int product(int x, int y) {
	return x * y;
}

int main() {
	int arr[product(2, 2)] = {1, 2, 3, 4};
	for(int i = 0; i < 4; ++i)
		std::cout << arr[i] << " \n"[i == 3];
}
