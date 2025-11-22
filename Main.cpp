#include <iostream>
#include <string>
#include <map>
#include <regex>
#include <algorithm>
#include <cctype>

std::map<std::string, int> ROMAN_DECIMAL_MAP = { {"I", 1},
												{"V", 5},
												{"X", 10},
												{"L", 50},
												{"C", 100},
												{"D", 500},
												{"M", 1000},
												{"_I", 1000},
												{"_V", 5000},
												{"_X", 10000},
												{"_L", 50000},
												{"_C", 100000},
												{"_D", 500000},
												{"_M", 1000000} };
std::regex VALID_ALGARISMS_REGEX("(_M){0,3}((_C_M)|(_C_D)|(_D)?(_C){0,3})((_X_C)|(_X_L)|(_L)?(_X){0,3})((_I_X)|(_I_V)|(_V)?)M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})", std::regex_constants::icase);
std::string SIMBOLOS[] = {"_M", "_C_M", "_D", "_C_D", "_C", "_X_C", "_L", "_X_L", "_X", "_I_X", "_V", "_I_V", "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
int VALORES[] = {1000000, 900000, 500000, 400000, 100000, 90000, 50000, 40000, 10000, 9000, 5000, 4000, 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

unsigned long toDecimal(std::string roman) {
	std::transform(roman.begin(), roman.end(), roman.begin(), ::toupper);
	long total = 0;
	for (int i = 0; i < roman.size(); i++)
	{
		if (roman.at(i) == '_' && i + 3 < roman.size() && roman.at(i + 2) == '_') {
			auto pair = roman.substr(i, 2);
			auto lookaheadPair = roman.substr(i + 2, 2);
			auto currentValue = ROMAN_DECIMAL_MAP[pair];
			auto nextValue = ROMAN_DECIMAL_MAP[lookaheadPair];
			if (nextValue > currentValue) {
				total = total + (nextValue - currentValue);
				i = i + 3;
			} else {
				total = total + currentValue;
				i = i + 1;
			}
		} else if (roman.at(i) == '_') {
			auto pair = roman.substr(i, 2);
			auto currentValue = ROMAN_DECIMAL_MAP[pair];
			total = total + currentValue;
			i = i + 1;
		} else {
			auto pair = roman.substr(i, 1);
			auto currentValue = ROMAN_DECIMAL_MAP[pair];
			long nextValue = 0;
			if (i + 1 < roman.size()) {
				auto nextChar = roman.substr(i + 1, 1);
				nextValue = ROMAN_DECIMAL_MAP[nextChar];
			}
			if (nextValue > currentValue) {
				total = total + (nextValue - currentValue);
				i++;
			} else {
				total = total + currentValue;
			}
		}
	}
	return total;
}

std::string toRoman(long numero) {
	std::string resultado = "";
	for (int i = 0; i < std::size(VALORES); i++) {
		while (numero >= VALORES[i]) {
			numero = numero - VALORES[i];
			resultado = resultado + SIMBOLOS[i];
		}
	}

	return resultado;
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "Para converter para romano: " << argv[0] << " <decimal>" << std::endl;
        std::cout << "Para converter para decimal: " << argv[0] << " <string>" << std::endl;
        std::cout << "Suporta algarismos romanos acima de 3999 usando _ (underscore). " << "E.g. _X_LMMLXIX" << std::endl;
		return 1;
	}
	std::smatch base_match;
	if (std::regex_match(argv[1], VALID_ALGARISMS_REGEX)) {
		std::cout << toDecimal(argv[1]) << std::endl;
		return 0;
	}

	long decimal;
	try {
		decimal = std::stoi(argv[1]);
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Número inválido" << std::endl;
		return 1;
	}
	catch (const std::out_of_range& e) {
		std::cerr << "Integer out of range." << std::endl;
		return 1;
	}

	if (0 < decimal < 3999999) {
		std::cout << toRoman(decimal) << std::endl;
	} else {
		std::cout << "Valor inválido" << std::endl;
	}
	return 0;
}
