#include <iostream>

using namespace std;

struct Struct1 {
  short s;
  int i;
  char c;
};

struct Struct2 {
  int i;
  char c;
  short s;
};

int main() {
  Struct1 a;
  Struct2 b;
  cout << "size of Struct1: " << sizeof(a) << '\n';
  cout << "size of Struct2: " << sizeof(b) << '\n';
}