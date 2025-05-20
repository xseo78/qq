#include <iostream>
#include <vector>

void find_magic_vectors(int N, int pos, int prev, int sum, int product, std::vector<int>& current) {
    if (pos == N) {
        if (sum == product) {
            for (int i = 0; i < N; ++i) {
                std::cout << current[i] << (i + 1 == N ? "\n" : ", ");
            }
        }
        return;
    }

    for (int i = prev; i <= 50; ++i) { 
        current[pos] = i;
        find_magic_vectors(N, pos + 1, i, sum + i, product * i, current);
    }
}

int main() {
    int N;
    std::cout << "Введіть N: ";
    std::cin >> N;

    if (N <= 0) {
        std::cout << "N має бути додатнім числом.\n";
        return 1;
    }

    std::vector<int> current(N);
    std::cout << "Чарівні вектори довжини " << N << ":\n";
    find_magic_vectors(N, 0, 1, 0, 1, current);

    return 0;
}
