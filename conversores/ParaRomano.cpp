#include "ParaRomano.hpp"

#include <string>
#include <cstdint>

std::string ParaRomano::DeLong(uint32_t numToConvert){
	std::string resultado = "";
	for (size_t i = 0; i < std::size(ParaRomano::VALORES); i++) {
		while (numToConvert >= ParaRomano::VALORES[i]) {
			numToConvert = numToConvert - ParaRomano::VALORES[i];
			resultado = resultado + std::string(ParaRomano::SIMBOLOS[i]);
		}
	}
	return resultado;
}