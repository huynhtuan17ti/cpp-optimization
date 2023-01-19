#include <iostream>

using namespace std;

int main() {
    char c = 'a';
    int i = 7;
    int *p = (int*) &c; // cast char pointer to int pointer (1 byte -> 4 bytes)
    // C-Style cast allows an integer pointer to point a char
    // int*p = static_cast<int*>(&c) // ---> error (static_cast will give an error if you do that)
    int *q = static_cast<int*>(&i); // it's ok

    cout << "p = " << *p << '\n';
    cout << "q = " << *q << '\n';

    cout << "-------------------" << '\n';
    // if we change the value of p, it will accidently change the value of i and q since p and (i or q) shares some memory points
    *p = 0x1234;
    cout << "p = " << *p << '\n';

    cout << "i = " << i << '\n';
    cout << "q = "  << *q << '\n';
}