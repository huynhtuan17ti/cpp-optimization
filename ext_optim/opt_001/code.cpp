#include <iostream>

using namespace std;

class HomeForSale {
 private:
  int m_price;

 public:
  HomeForSale(int price) : m_price(price) {}
  ~HomeForSale() {}
  int getPrice() { return m_price; }
};

class HomeForSaleV2 {
 private:
  int m_price;
  HomeForSaleV2(const HomeForSaleV2&);
  HomeForSaleV2& operator=(const HomeForSaleV2&);

 public:
  HomeForSaleV2(int price) : m_price(price) {}
  ~HomeForSaleV2() {}
  int getPrice() { return m_price; }
};

class Uncopyable {
 protected:
  Uncopyable() {}
  ~Uncopyable() {}

 private:
  Uncopyable(const Uncopyable&);
  Uncopyable& operator=(const Uncopyable&);
};

class HomeForSaleV3 : private Uncopyable {
 private:
  int m_price;

 public:
  HomeForSaleV3(int price) : m_price(price){};
  int getPrice() { return m_price; }
};

int main() {
  HomeForSale h1(5);
  HomeForSale h2 = h1;

  cout << "Price of h1: " << h1.getPrice() << '\n';
  cout << "Price of h2: " << h2.getPrice() << '\n';

  HomeForSaleV2 h1_v2(5);
  // HomeForSaleV2 h2_v2(h1); ----> error here

  HomeForSaleV3 h1_v3(5);
  // HomeForSaleV3 h2_v3 = h1_v3; ----> error here
}