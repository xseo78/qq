#include <iostream>
#include <cstdlib>
#include <ctime>

int rand(int low, int high) {
    return low + std::rand() % (high - low + 1);
}

int main() {
    std::srand(std::time(0));

    for (int i = 0; i < 10; ++i) {
        std::cout << rand(5, 15) << " ";
    }

    return 0;
}
