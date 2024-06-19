#include <iostream>
#include <sstream>
#include <set>
#include <string>

bool isDelimiter(char ch) {
    return std::isspace(ch) || std::ispunct(ch);
}

void splitText(const std::string& text, std::set<std::string>& uniqueWords, std::string& result) {
    std::string word;
    for (char ch : text) {
        if (isDelimiter(ch)) {
            if (!word.empty() && uniqueWords.find(word) == uniqueWords.end()) {
                uniqueWords.insert(word);
                if (!result.empty()) {
                    result += ' ';
                }
                result += word;
            }
            word.clear();
        } else {
            word += ch;
        }
    }
    if (!word.empty() && uniqueWords.find(word) == uniqueWords.end()) {
        uniqueWords.insert(word);
        if (!result.empty()) {
            result += ' ';
        }
        result += word;
    }
}

std::string removeDuplicateWords(const std::string& text) {
    std::set<std::string> uniqueWords;
    std::string result;
    splitText(text, uniqueWords, result);
    return result;
}

int main() {
    std::string text;
    std::cout << "Enter: ";
    std::getline(std::cin, text);

    std::string result = removeDuplicateWords(text);
    std::cout << "Processed text: " << result << std::endl;

    return 0;
}
