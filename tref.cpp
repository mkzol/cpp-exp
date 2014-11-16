#include <iostream>
struct Bar {
int x;
Bar(int i) : x(i) {}
};
void foo( Bar & b ) {
std::cout << "lvalue" << std::endl;
}
void foo( Bar && b ) {
std::cout << "rvalue" << std::endl;
}
int main() {
Bar b(3);
foo(b);
foo(4);
}
