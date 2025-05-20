#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    for (int a = 1; a <= n; ++a) {
        for (int b = a; b <= n; ++b) { 
            int c2 = a * a + b * b;
            int c = std::sqrt(c2);
            if (c <= n && c * c == c2) {
                std::cout << a << " " << b << " " << c << std::endl;
            }
        }
    }

    return 0;
}
