#include <iostream>

int main() {
    double x, y;
    std::cin >> x >> y;
    bool p = (x > y);
    std::cout << (p ? x : y);
    return 0;
}
