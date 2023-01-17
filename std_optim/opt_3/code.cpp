#include <variant>
#include <iostream>
#include <string>

using namespace std;

int main() {
    variant<int, string> v;
    v = 100;
    cout << "Get int from variant: " << get<int>(v) << '\n';
    cout << "Get index 0 from variant: " << get<0>(v) << '\n';

    cout << "Get string from variant: ";
    try {
        cout << get<string>(v) << '\n';
    }catch (const std::bad_variant_access& ex) {
        std::cout << ex.what() << '\n';
    }

    v = "abc";
    cout << "Get string from variant: " << get<string>(v) << '\n';
    cout << "Get index 1 from variant: " << get<1>(v) << '\n';

    cout << "Get index 0 from variant: ";
    try {
        cout << get<0>(v) << '\n';
    }catch (const std::bad_variant_access& ex) {
        std::cout << ex.what() << '\n';
    }
}