#include <iostream>
#include <string>
#include <vector>

using namespace std;

string intToRoman(int num) {
    // Сопоставление чисел и их римских обозначений (в порядке убывания)
    vector<pair<int, string>> roman_symbols = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    string result = "";
    for (const auto& symbol : roman_symbols) {
        while (num >= symbol.first) {
            result += symbol.second;
            num -= symbol.first;
        }
    }
    return result;
}

// Пример вызова: intToRoman(1994) вернет "MCMXCIV"