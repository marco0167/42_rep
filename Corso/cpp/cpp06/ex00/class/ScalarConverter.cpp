#include "./ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &rhs)
{
	*this = rhs;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
	return *this;
}

std::string	decimalPart(double val) {
	std::string	decimal = "";

	int intpart = static_cast<int>(val);
	float decpart = val - intpart;
	if (decpart == 0.0f)
		decimal = ".0";

	return decimal;
}

void ScalarConverter::convert(std::string value)
{
	try {
		int		intVal = std::stoi(value);
		char	charVal = intVal;

		if (intVal <= 32 || intVal > 126)
			std::cout << "char: " << "Non displayable" << std::endl;
		else
			std::cout << "char: " << "'" << charVal << "'" << std::endl;
		std::cout << "int: " << intVal << std::endl;
	} catch(...) {
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
	}

	try {
		float	floatVal = std::stof(value);

		std::cout << "float: " << floatVal << decimalPart((double)floatVal) << "f" << std::endl;
	} catch (...) {
		std::cout << "float: " << "impossible" << std::endl;
	}

	try {
		double	doubleVal = std::stod(value);

		std::cout << "double: " << doubleVal << decimalPart(doubleVal) << std::endl;
	} catch (...) {
		std::cout << "double: " << "impossible" << std::endl;
	}
}
