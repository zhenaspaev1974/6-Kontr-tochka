#include "pch.h"
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
	// Проходим по всем парам (число - символ)
	for (const auto& symbol : roman_symbols) {
		// Пока текущее число больше или равно значению символа
		while (num >= symbol.first) {
			result += symbol.second; // Добавляем символ в ответ
			num -= symbol.first;     // Вычитаем значение из числа
		}
	}
	return result;
}

int main() {
	// Пример из задания
	int number1 = 42;
	cout << "Number: " << number1 << " -> Roman: " << intToRoman(number1) << "\n";

	// Пример из текста задания про 1994 год
	int number2 = 1994;
	cout << "Number: " << number2 << " -> Roman: " << intToRoman(number2) << "\n";

	// Можно добавить ввод с клавиатуры
	int user_num;
	cout << "\nEnter your number (from 1 to 3999): ";
	cin >> user_num;
	if (user_num > 0) {
		cout << "Result: " << intToRoman(user_num) << "\n";
	}

	return 0;
}
