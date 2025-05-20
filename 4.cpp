#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int original = n;
    std::cout << original << " = ";

    bool first = true;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            if (!first) std::cout << ", ";
            std::cout << i;
            n /= i;
            first = false;
        }
    }

    if (n > 1) {
        if (!first) std::cout << ", ";
        std::cout << n;
    }

    std::cout << std::endl;
    return 0;
}
