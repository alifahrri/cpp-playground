#include <iostream>

struct C {
  C() {}
  C(const C&) { std::cout << "A copy was made.\n"; }
};

C f() {
  return C();
}

C g() {
    C c;
    return c;
}

int main() {
  std::cout << "Hello World!\n";
  C obj0 = f();
  C obj1 = g();
  C obj2(f());
  C obj3(g());
  return 0;
}