#include <iostream>

double x1, Y1, x2, y2, x3, y3;

double getsqrt(double x) {
    double l = 0, r = 1e9;
    for (int i = 0; i < 1000; i++) {
        double mid = (l + r) / 2;
        if (mid * mid > x) r = mid; else l = mid;
    }

    return l;
}

double getpow(double x, int st) {
    double res = x;
    for (int i = 2; i <= st; i++) res *= x;

    return res;
}

double arccos(double x) {
    double res = x, p = 1, px = x;

    for (int i = 1; i <= 1000; i++) {
        p *= (2 * i - 1);
        p /= (2 * i);
        px *= x * x;

        res += ((p * px) / (2 * i + 1));
    }

    return 1.57079632679 - res;
}

int main() {
    std::cin >> x1 >> Y1 >> x2 >> y2 >> x3 >> y3;

    double AB = getsqrt((x1 - x2) * (x1 - x2) + (Y1 - y2) * (Y1 - y2));
    double BC = getsqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    double AC = getsqrt((x1 - x3) * (x1 - x3) + (Y1 - y3) * (Y1 - y3));

    std::cout << "AB = " << AB << '\n';
    std::cout << "BC = " << BC << '\n';
    std::cout << "AC = " << AC << "\n\n";

    std::cout << "P = " << AB + BC + AC << '\n';

    double p = (AB + BC + AC) / 2;
    double S = getsqrt(p * (p - BC) * (p - AC) * (p - AB));
    double S2 = abs(x1 * y2 + x2 * y3 + x3 * Y1 - Y1 * x2 - y2 * x3 - y3 * x1) / 2;
    double S3 = abs((x2 - x1) * (y3 - Y1) - (x3 - x1) * (y2 - Y1))/2;

    std::cout << "S = " << S3 << '\n';
    std::cout << "S = " << S2 << '\n';
    std::cout << "S = " << S << "\n\n";
    std::cout << "h_a = " << 2 * S / BC << '\n';
    std::cout << "h_b = " << 2 * S / AC << '\n';
    std::cout << "h_c = " << 2 * S / AB << "\n\n";

    std::cout << "l_a = " << getsqrt(AC * AB * (1 - (BC * BC) / ((AC + AB) * (AC + AB)))) << '\n';
    std::cout << "l_b = " << getsqrt(AB * BC * (1 - (AC * AC) / ((AB + BC) * (AB + BC)))) << '\n';
    std::cout << "l_c = " << getsqrt(AC * BC * (1 - (AB * AB) / ((AC + BC) * (AC + BC)))) << "\n\n";

    double R = (AB * BC * AC) / (4 * S), r = S / ((AB + BC + AC) / 2);
    std::cout << "R = " << R << '\n';
    std::cout << "S_R = " << 3.1415 * R * R << '\n';
    std::cout << "L_R = " << 2 * 3.1415 * R << '\n';
    std::cout << "r = " << r << '\n';
    std::cout << "S_r = " << 3.1415 * r * r << '\n';
    std::cout << "L_r = " << 2 * 3.1415 * r << "\n\n";

    double A = arccos((AB * AB + AC * AC - BC * BC) / (2 * AB * AC));
    double B = arccos((AB * AB + BC * BC - AC * AC) / (2 * AB * BC));
    double C = arccos((BC * BC + AC * AC - AB * AB) / (2 * BC * AC));

    std::cout << "<A = " << A * 180 / 3.1415 << "; " << A << '\n';
    std::cout << "<B = " << B * 180 / 3.1415 << ", " << B << '\n';
    std::cout << "<C = " << C * 180 / 3.1415 << ", " << C << '\n';
    return 0;
}
