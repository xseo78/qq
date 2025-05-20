#include <iostream>
#include <cmath>

// Перевірка, чи є число простим
bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= std::sqrt(x); ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    std::cin >> n;

    for (int i = n; i <= 2 * n - 2; ++i) {
        if (is_prime(i) && is_prime(i + 2)) {
            std::cout << "(" << i << ", " << i + 2 << ")" << std::endl;
        }
    }

    return 0;
}
