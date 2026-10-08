#include "class2.h"
#include <iostream>

X::X() : x1(0), x2(0) {}
X::X(int32_t other_x1, int32_t other_x2) : x1(other_x1), x2(other_x2) {}
X::~X() {}
void X::show() const {
    std::cout << "x1 = " << x1 << ' ' << "x2 = " << x2;
}
void X::set() {
    std::cout << "Enter new x1, x2: ";
    std::cin >> x1 >> x2;
}

Y::Y() : X(), y(0) {}
Y::Y(int32_t other_x1, int32_t other_x2, int32_t other_y) : X(other_x1, other_x2), y(other_y) {}
Y::~Y() {}
void Y::show() const {
    X::show();
    std::cout << " y = " << y;
}
void Y::set() {
    std::cout << "Enter new x1, x2, y: ";
    std::cin >> x1 >> x2 >> y;
}
int32_t Y::Run() {
    return x1 * x1 + x2 * x2 + y * y;
}