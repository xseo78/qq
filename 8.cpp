#include <iostream>
#include <sstream>
#include <vector>
#include <string>

std::string justify_line(const std::vector<std::string>& words, int width) {
    if (words.empty()) return "";

    int total_length = 0;
    for (const auto& word : words) total_length += word.size();

    int spaces = width - total_length;
    int gaps = words.size() - 1;

    std::string result;

    if (gaps == 0) {
        
        result = words[0] + std::string(spaces, ' ');
    } else {
        int even_space = spaces / gaps;
        int extra = spaces % gaps;

        for (int i = 0; i < gaps; ++i) {
            result += words[i];
            result += std::string(even_space + (i < extra ? 1 : 0), ' ');
        }
        result += words.back();
    }

    return result;
}

void format_paragraph(const std::string& paragraph, int width) {
    std::istringstream iss(paragraph);
    std::vector<std::string> line_words;
    std::string word;
    int line_length = 0;

    while (iss >> word) {
        if (line_length + word.length() + line_words.size() > width) {
            std::cout << justify_line(line_words, width) << "\n";
            line_words.clear();
            line_length = 0;
        }
        line_words.push_back(word);
        line_length += word.length();
    }

    
    if (!line_words.empty()) {
        std::string last_line;
        for (size_t i = 0; i < line_words.size(); ++i) {
            last_line += line_words[i];
            if (i + 1 < line_words.size()) last_line += " ";
        }
        last_line += std::string(width - last_line.length(), ' ');
        std::cout << last_line << "\n";
    }
}

int main() {
    int width;
    std::string text, line;

    std::cin >> width;
    std::cin.ignore(); 

    if (width <= 50) {
        std::cout << "Ширина має бути більше 50!" << std::endl;
        return 1;
    }

    while (std::getline(std::cin, line)) {
        text += line + "\n";
    }

    std::istringstream input(text);
    std::string paragraph;
    while (std::getline(input, paragraph, '\n')) {
        if (paragraph.empty()) {
            std::cout << "\n"; 
        } else {
            format_paragraph(paragraph, width);
        }
    }

    return 0;
}
