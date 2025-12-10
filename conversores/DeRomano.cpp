#include "DeRomano.hpp"

#include <cstdint>
#include <string_view>

uint32_t DeRomano::paraLong(std::string_view algarismos) {
	uint32_t total = 0;
	size_t indiceCaractereAtual = 0;
	while (indiceCaractereAtual < algarismos.length()) {
		bool vinculumPair = algarismos.at(indiceCaractereAtual) == '_'
								&& indiceCaractereAtual + 3 < algarismos.length()
								&& algarismos.at(indiceCaractereAtual + 2) == '_'
								&& DeRomano::ROMAN_DECIMAL_MAP.contains(algarismos.substr(indiceCaractereAtual, 4));
		bool vinculumSingle__NormalPair = algarismos.at(indiceCaractereAtual) == '_'
											|| indiceCaractereAtual + 1 < algarismos.length()
												&& DeRomano::ROMAN_DECIMAL_MAP.contains(algarismos.substr(indiceCaractereAtual, 2));

		auto key = vinculumPair
					? algarismos.substr(indiceCaractereAtual, 4)
					: vinculumSingle__NormalPair
						? algarismos.substr(indiceCaractereAtual, 2)
						: algarismos.substr(indiceCaractereAtual, 1);

		indiceCaractereAtual += key.length();
		total += DeRomano::ROMAN_DECIMAL_MAP.at(key);
	}
	return total;
}