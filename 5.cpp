#include <iostream>
#include <string>

// Функція перевірки, чи є число паліндромом
bool is_palindrome(int num) {
    std::string s = std::to_string(num);
    std::string reversed = s;
    std::reverse(reversed.begin(), reversed.end());
    return s == reversed;
}

int main() {
    for (int i = 1; i < 100; ++i) {
        if (is_palindrome(i) && is_palindrome(i * i)) {
            std::cout << i << " -> " << i * i << std::endl;
        }
    }
    return 0;
}
