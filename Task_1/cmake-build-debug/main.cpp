#include <iostream>

int main() {
    double x, x2, ans1, ans2;
    std::cin >> x;

    x2 = x * x;
    ans1 = x * (23 * x2 + 32);
    ans2 = 69 * x2 + 8;

    std::cout << ans1 + ans2 << ' ' << ans2 - ans1;

    return 0;
}
