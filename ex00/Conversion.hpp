#ifndef	CONVERSION_HPP
#define	CONVERSION_HPP

#include <iostream>
# include <limits>
# include <cmath>

class Conversion
{
	private:
		char	*ch;
		int		type;
		char	ch_char;
		int		ch_int;
		double	ch_double;
		float	ch_float;

		// определяем тип пришедшего параметра
		int isChar(std::string str);
		int isStr(std::string str);
		int isDigit(std::string str);

	public:
		Conversion();
		Conversion(const Conversion &other);
		Conversion& operator=(const Conversion &other);
		~Conversion();

		Conversion(char *ch);
};

#endif
