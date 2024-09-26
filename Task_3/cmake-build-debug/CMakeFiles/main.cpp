#include <iostream>
#include <iomanip>

int main() {
    double x;
    std::cin >> x;
    std::cout << std::fixed << std::setprecision(5) << x * 11 / 10;

    return 0;
}
