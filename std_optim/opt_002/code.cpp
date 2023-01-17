#include <iostream>
#include <utility>

using namespace std;

void may_throw();
void no_throw() noexcept;


int main() {
    cout << boolalpha
        << "Is may_throw() noexcept? " << noexcept(may_throw()) << '\n'
        << "Is no_throw() noexcept? " << noexcept(no_throw()) << '\n';
}