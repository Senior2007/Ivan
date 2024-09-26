#include <iostream>

double p, q, PI = 3.1415;

double getsqrt(double x) {
    double l = 0, r = x;
    for (int i = 0; i < 1000; i++) {
        double mid = (l + r) / 2;
        if (mid * mid > x) r = mid; else l = mid;
    }

    return l;
}

double sqrt3(double x) {
    double l = x, r = -1, m;

    if (x > 1) l = 1, r = x; else
    if (x > 0) l = 0, r = 1; else
    if (x > -1) l = -1, r = 0;

    for (int i = 0; i < 1000; i++) {
        m = (l + r) / 2;
        if (m * m * m < x) l = m; else r = m;
    }

    return l;
}

double getcos(double x) {
    double res = 1, cx = 1, cp = 1;

    for (int i = 1; i <= 100; i++) {
        cx *= x * x;
        cp *= (2 * i - 1) * (2 * i);
        if (i % 2 == 0) res += (cx / cp); else res -= (cx / cp);
    }

    return res;
}

double getatan(double x) {
    if (x > 1) return PI / 2 - getatan(1 / x); else
    if (x < -1) return -PI / 2 - getatan(1 / x);

    double res = x, pr = x;
    for (int i = 1; i <= 3; i++) {
        pr *= x * x;
        double cnt = pr; cnt /= (2 * i + 1);
        if (i % 2 == 0) res += cnt; else res -= cnt;
    }

    return res;
}

int main() {
    std::cout << "Введите p и q\n";
    std::cin >> p >> q;

    std::cout << "Корни :\n";
    double D = (q / 2) * (q / 2) + (p / 3) * (p / 3) * (p / 3), f;

    if (D == 0) {
        std::cout << 0;
        return 0;
    }

    if (D > 0) {
        std::cout << sqrt3(-q / 2 + getsqrt(D)) + sqrt3(-q / 2 - getsqrt(D)) << " ";
        return 0;
    }

    if (q < 0) f = getatan(getsqrt(-D) / (-q / 2));
    if (q > 0) f = getatan(getsqrt(-D) / (-q / 2)) + PI;
    if (q == 0) f = PI / 2;

    std::cout << 2 * getsqrt(-p / 3) * getcos(f / 3) << '\n';
    std::cout << 2 * getsqrt(-p / 3) * getcos(f / 3 + (2 * PI) / 3) << '\n';
    std::cout << 2 * getsqrt(-p / 3) * getcos(f / 3 + (4 * PI) / 3) << '\n';
    return 0;
}

