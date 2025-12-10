#include "DeRomano.hpp"

#include <string_view>

unsigned long DeRomano::paraLong(std::string_view algarismos) {
	unsigned long total = 0;
	for (int i = 0; i < algarismos.size(); i++)
	{
		if (algarismos.at(i) == '_' && i + 3 < algarismos.size() && algarismos.at(i + 2) == '_') {
			auto pair = algarismos.substr(i, 2);
			auto lookaheadPair = algarismos.substr(i + 2, 2);
			auto currentValue = DeRomano::ROMAN_DECIMAL_MAP.at(pair);
			auto nextValue = DeRomano::ROMAN_DECIMAL_MAP.at(lookaheadPair);
			if (nextValue > currentValue) {
				total = total + (nextValue - currentValue);
				i = i + 3;
			}
			else {
				total = total + currentValue;
				i = i + 1;
			}
		}
		else if (algarismos.at(i) == '_') {
			auto pair = algarismos.substr(i, 2);
			auto currentValue = DeRomano::ROMAN_DECIMAL_MAP.at(pair);
			total = total + currentValue;
			i = i + 1;
		}
		else {
			auto pair = algarismos.substr(i, 1);
			auto currentValue = DeRomano::ROMAN_DECIMAL_MAP.at(pair);
			long nextValue = 0;
			if (i + 1 < algarismos.size()) {
				auto nextChar = algarismos.substr(i + 1, 1);
				nextValue = DeRomano::ROMAN_DECIMAL_MAP.at(nextChar);
			}
			if (nextValue > currentValue) {
				total = total + (nextValue - currentValue);
				i++;
			}
			else {
				total = total + currentValue;
			}
		}
	}
	return total;
}