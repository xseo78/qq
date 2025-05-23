#include <iostream>
#include <vector>

int main() {
    const int n = 1000;
    std::vector<bool> is_prime(n + 1, true);

    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            std::cout << i << " ";
        }
    }

    return 0;
}
