#include "conversores/ParaRomano.hpp"
#include "conversores/DeRomano.hpp"

#include <regex>
#include <cctype>
#include <string>
#include <cstdint>
#include <iostream>
#include <algorithm>

std::regex VALID_ALGARISMS_REGEX("(_M){0,3}((_C_M)|(_C_D)|(_D)?(_C){0,3})((_X_C)|(_X_L)|(_L)?(_X){0,3})((_I_X)|(_I_V)|(_V)?)M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})", std::regex_constants::icase);

int main(int argc, char* argv[]) {
	if (argc < 2) {
        std::cout << "Para converter de romano: " << argv[0] << " <string>" << std::endl;
		std::cout << "Para converter para romano: " << argv[0] << " <decimal>" << std::endl;
        std::cout << "\nSuporta algarismos romanos acima de 3999 usando _ (underscore). " << "E.g. _X_LMMLXIX" << std::endl;
		return 1;
	}
	
	if (std::regex_match(argv[1], VALID_ALGARISMS_REGEX)) {
		std::string romano = argv[1];
		std::transform(romano.begin(), romano.end(), romano.begin(), ::toupper);
		std::cout << DeRomano::paraLong(romano) << std::endl;
		return 0;
	}
	
	int32_t decimal;
	try {
		decimal = std::stoi(argv[1], nullptr, 0);
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Valor inválido" << std::endl;
		return 1;
	}
	catch (const std::out_of_range& e) {
		std::cerr << "Out of range." << std::endl;
		return 1;
	}
	
	if (0 < decimal && decimal <= 3999999) {
		std::cout << ParaRomano::DeLong(decimal) << std::endl;
	} else {
		std::cout << "O valor deve estar entre 0 e 3999999" << std::endl;
	}
	return 0;
}
