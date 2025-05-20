#include <iostream>
#include <sstream>
#include <bitset>
#include <vector>
#include <string>


std::string phrase_to_bits(const std::string& phrase) {
    std::string bits;
    for (char c : phrase) {
        std::bitset<8> b(c);
        bits += b.to_string();
    }
    return bits;
}


std::string hide_message(const std::string& cover_text, const std::string& secret) {
    std::string bits = phrase_to_bits(secret);

    std::istringstream iss(cover_text);
    std::vector<std::string> words;
    std::string word;
    while (iss >> word) {
        words.push_back(word);
    }

    if (bits.size() > words.size() - 1) {
        return "Недостатньо слів у тексті для приховування фрази!";
    }

    std::string result;
    for (size_t i = 0; i < bits.size(); ++i) {
        result += words[i];
        result += (bits[i] == '0' ? " " : "  ");
    }

    for (size_t i = bits.size(); i < words.size(); ++i) {
        result += words[i];
        if (i + 1 < words.size()) result += " ";
    }

    return result;
}


std::string extract_message(const std::string& stego_text, int num_chars) {
    std::vector<char> bytes;

    std::istringstream iss(stego_text);
    std::string token;
    std::string prev;
    std::string bit_sequence;

    while (iss >> token) {
        if (!prev.empty()) {
            size_t pos = stego_text.find(prev + " ");
            if (pos != std::string::npos) {
                if (stego_text[pos + prev.size()] == ' ' &&
                    stego_text[pos + prev.size() + 1] == ' ') {
                    bit_sequence += '1';
                } else {
                    bit_sequence += '0';
                }
            }
        }
        prev = token;

        if (bit_sequence.length() >= num_chars * 8) break;
    }

    std::string result;
    for (int i = 0; i < num_chars; ++i) {
        std::bitset<8> b(bit_sequence.substr(i * 8, 8));
        result += static_cast<char>(b.to_ulong());
    }

    return result;
}

int main() {
    std::string cover_text = "Це приклад базового тексту який містить досить слів для приховання повідомлення без помітності.";
    std::string secret = "OK(XD)";

    std::cout << "Оригінальний текст:\n" << cover_text << "\n\n";

    std::string encoded = hide_message(cover_text, secret);
    std::cout << "Зашифрований текст:\n" << encoded << "\n\n";

    std::string decoded = extract_message(encoded, secret.size());
    std::cout << "Розшифроване повідомлення: " << decoded << "\n";

    return 0;
}
