#include <iostream>

int main() {
    int t;
    double c, d, z, x, f;
    std::cout << "Введите c, d, z, t. t - тип функции (0, 1 или 2)\n";
    std::cin >> c >> d >> z >> t;
    if (z < 1) {
        x = z * z + 1;

        switch (t) {
            case 1:
                f = 2 * x;
                break;
            case 2:
                f = pow(x, 3);
                break;
            default:
                f = x / 3;
        }

        std::cout << "y=" << (d * f * exp(pow(sin(x), 3)) + c * log(x + 1))/sqrt(x) << '\n';
        std::cout << "Вычисления проводились при :\n";
        std::cout << "1. x = z^2 + 1\n";

        if (t == 1) std::cout << "2. f(x) = 2 * x\n";
        if (t == 2) std::cout << "2. f(x) = x ^ 3\n";
        if (t == 3) std::cout << "2. f(x) = x / 3\n";

        return 0;
    }

    x = z - 1;

    switch (t) {
        case 1:
            f = 2 * x;
            break;
        case 2:
            f = pow(x, 3);
            break;
        default:
            f = x / 3;
    }

    std::cout << "y=" << (d * f * exp(pow(sin(x), 3)) + c * log(x + 1))/sqrt(x) << '\n';
    std::cout << "Вычисления проводились при :\n";
    std::cout << "1. x = z - 1\n";

    if (t == 1) std::cout << "2. f(x) = 2 * x\n";
    if (t == 2) std::cout << "2. f(x) = x ^ 3\n";
    if (t == 3) std::cout << "2. f(x) = x / 3\n";


    return 0;
}
