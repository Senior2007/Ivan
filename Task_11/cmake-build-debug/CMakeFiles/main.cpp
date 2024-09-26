#include <iostream>

int main() {
    int h1, m1, h2, m2;
    std::cin >> h1 >> m1 >> h2 >> m2;

    int c1 = h1 * 60 + m1, c2 = h2 * 60 + m2;
    int min = ((c1 < c2) ? c2 - c1 : 24 * 60 - (c1 - c2));

    std::cout << min / 60 << " часов " << min % 60 << " минут";

    return 0;
}
