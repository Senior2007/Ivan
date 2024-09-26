#include <iostream>

double x1, Y1, x2, y2, r, R;

double gabs(double x) {
    if (x < 0) x = -x;
    return x;
}

double getsqrt(double x) {
    double l = 0, r = 1e9;
    for (int i = 0; i < 1000; i++) {
        double mid = (l + r) / 2;
        if (mid * mid > x) r = mid; else l = mid;
    }

    return l;
}

int main() {
    std::cin >> x1 >> Y1 >> r >> x2 >> y2 >> R;

    double d = getsqrt((x2 - x1) * (x2 - x1) + (y2 - Y1) * (y2 - Y1));

    if (d + r <= R) {
        std::cout << "Да";
    } else if (d + R <= r) {
        std::cout << "Да, но справедливо обратное для двух фигур";
    } else if (d < r + R) {
        std::cout << "Фигуры пересекаются";
    } else {
        std::cout << "Ни одно условие не выполнено";
    }

    return 0;
}
