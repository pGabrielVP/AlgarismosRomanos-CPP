#include <map>
#include <string>
#include <string_view>

#ifndef DeRomano_H
#define DeRomano_H

class DeRomano {
	public:
		const inline static std::map<std::string_view, int> ROMAN_DECIMAL_MAP = { {"I", 1},
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
		static unsigned long paraLong(std::string algarismos);
};

#endif
