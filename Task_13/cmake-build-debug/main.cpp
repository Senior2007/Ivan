#include <iostream>

int a, b, mod = 1e9 + 7;

int bpow(int a, int b) {
    if (b == 0) return 1;
    int c;

    if (b % 2){
        c = a * bpow(a, b - 1); c %= mod;
    } else {
        c = bpow(a, b / 2); c %= mod; c *= c; c %= mod;
    }

    std::cout << "a = " << a << "; b = " << b << "; a ^ b = " << c << '\n';
    return c;
}

int main() {
    std::cin >> a >> b;
    int ans = bpow(a, b);
    return 0;
}
