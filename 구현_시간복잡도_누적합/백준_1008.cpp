#include <iostream>

int main() {
    double a, b;
    std::cin >> a;
    std::cin >> b;
    std::cout.precision(10);
    std::cout << a / b;
    return 0;
}