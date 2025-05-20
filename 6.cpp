#include <iostream>
#include <vector>

std::string number_to_words(int n) {
    if (n < 0 || n > 1000) return "Число поза межами [0; 1000]";

    std::vector<std::string> ones = {
        "", "один", "два", "три", "чотири", "п’ять", "шість", "сім", "вісім", "дев’ять"
    };

    std::vector<std::string> teens = {
        "десять", "одинадцять", "дванадцять", "тринадцять", "чотирнадцять",
        "п’ятнадцять", "шістнадцять", "сімнадцять", "вісімнадцять", "дев’ятнадцять"
    };

    std::vector<std::string> tens = {
        "", "", "двадцять", "тридцять", "сорок", "п’ятдесят",
        "шістдесят", "сімдесят", "вісімдесят", "дев’яносто"
    };

    std::vector<std::string> hundreds = {
        "", "сто", "двісті", "триста", "чотириста", "п’ятсот",
        "шістсот", "сімсот", "вісімсот", "дев’ятсот"
    };

    if (n == 0) return "нуль";
    if (n == 1000) return "тисяча";

    std::string result;

    int h = n / 100;
    int t = (n / 10) % 10;
    int o = n % 10;

    if (h > 0) result += hundreds[h] + " ";

    if (t == 1) {
        result += teens[o];
    } else {
        if (t > 1) result += tens[t] + " ";
        if (o > 0) result += ones[o];
    }

    return result;
}

int main() {
    int n;
    std::cin >> n;

    std::cout << number_to_words(n) << std::endl;

    return 0;
}
