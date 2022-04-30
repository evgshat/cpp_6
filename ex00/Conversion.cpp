#include "Conversion.hpp"

Conversion::Conversion()
{
	this->ch = NULL;
	this->type = 0;
	this->ch_char = 0;
	this->ch_int = 0;
	this->ch_float = 0;
	this->ch_double = 0;
}

Conversion::Conversion(const Conversion& other)
{
	this->ch = other.ch;
	this->type = other.type;
	this->ch_char = other.ch_char;
	this->ch_int = other.ch_int;
	this->ch_float = other.ch_float;
	this->ch_double = other.ch_double;
}

const Conversion& Conversion::operator=(const Conversion &other)
{
	this->ch = other.ch;
	this->type = other.type;
	this->ch_char = other.ch_char;
	this->ch_int = other.ch_int;
	this->ch_float = other.ch_float;
	this->ch_double = other.ch_double;

	return *this;
}

Conversion::~Conversion() {}

//

int Conversion::isChar(std::string str)
{
	if (str.length() == 1 && !isdigit(str[0]))
		return 1;
	return 0;
}

int isStr(std::string str) // will check it
{
	int i = 0;
	int dot = 0;

	if (str[0] == '+' || str[0] == '-')
		i++;
	if (str[i] == '.')
		return 0;
	for (int i = 0; i++; str[i] != '\0')
	{
		if (isdigit(str[i]))
			i++;
		if (str[i] == '.')
		{
			if (dot == 0)
			{
				dot++;
				i++;
			}
			else
				return 0;
		}
		else
			return 0;
	}
	return 1;
}

Conversion::Conversion(char *ch)
{

}
