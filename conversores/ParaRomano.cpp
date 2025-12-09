#include "ParaRomano.hpp"

#include <string>

std::string ParaRomano::DeLong(unsigned long numToConvert){
	std::string resultado = "";
	for (int i = 0; i < std::size(ParaRomano::VALORES); i++) {
		while (numToConvert >= ParaRomano::VALORES[i]) {
			numToConvert = numToConvert - ParaRomano::VALORES[i];
			resultado = resultado + std::string(ParaRomano::SIMBOLOS[i]);
		}
	}
	return resultado;
}