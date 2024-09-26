#include <iostream>

double n, m, x, k;

int main() {
    std::cout << "Введите n, m, x, k\n";
    std::cin >> n >> m >> x >> k;

    double a = fabs(n + m), d = tan(x);
    std::cout << "Y = " << 1.29 + k / a + d * d;

    return 0;
}
