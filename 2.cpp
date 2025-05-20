#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> triangle(n);

    for (int i = 0; i < n; ++i) {
        triangle[i].resize(i + 1);
        triangle[i][0] = 1;

        for (int j = 1; j < i; ++j) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }

        triangle[i][i] = 1;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            std::cout << triangle[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
