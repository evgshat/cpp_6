#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cctype>

void print(char c, int i, float f, double d)
{
	if (isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	if (f - static_cast<int>(f) == 0)
	{
		std::cout << "float: " <<  f << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " <<  f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
}

void print_nan_inf(const std::string& str)
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: " << str << "f\n";
	std::cout << "double: " << str << "\n";
}

bool print_float(std::string str, char c, int i, float f, double d)
{
	std::stringstream ss;
	bool dot = false;
	int ind = 0;

	if (str == "-inff" || str == "+inff" || str == "nanf" || str == "inff")
	{
		str.erase(str.size() - 1);
		print_nan_inf(str);
		return false;
	}
	if (str.size() > 1 && str[str.length() - 1] == 'f')
	{
		if (str[0] == '-' || str[0] == '+')
			ind++;
		if (!isdigit(str[ind]))
			return false;
		for (int it = ind; it < str.length() - 1; it++)
		{
			if (str[it] == '.' && dot == false)
			{
					dot = true;
					continue ;
			}
			if (!isdigit(str[it]))
				return false;
		}
		str = str.substr(0, str.size() - 1);
		ss << str;
		ss >> f;
		c = static_cast<char>(f);
		i = static_cast<int>(f);
		d = static_cast<double>(f);
		print(c, i, f, d);
		return true;
	}
	return false;
}

bool print_double(std::string str, char c, int i, float f, double d) // переделать принт, так как печатается одна точность
{
	if (str == "-inf" || str == "+inf" || str == "nan" || str == "inf")
	{
		print_nan_inf(str);
		return false;
	}
	if (str.find('.') == str.npos)
		return false;
	str.push_back('f');
	return print_float(str, c, i, f, d);
}

bool print_int(std::string str, char c, int i, float f, double d)
{
	int ind = 0;
	std::stringstream ss;
	ss << str;
	if (str.size() == 1 && !isdigit(str[0]))
		return false;
	else if (str.size() > 1)
	{
		if (str[0] == '-' || str[0] == '+')
			ind++;
		for (int it = ind; it < str.length(); it++)
			if (!isdigit(str[it]))
				return false;
	}
	ss >> i;
	c = static_cast<char>(i);
	f = static_cast<float>(i);
	d = static_cast<double>(i);
	print(c, i, f, d);
	return true;
}

bool print_char(std::string str, char c, int i, float f, double d)
{
	std::stringstream ss;
	ss << str;

	if (str.size() != 1 || isdigit(str[0])) return false;
	ss >> c;
	i = static_cast<int>(c);
	f = static_cast<float>(c);
	d = static_cast<double>(c);
	print(c, i, f, d);
	return true;
}

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw ("Invalid args !");
		std::string str = argv[1];
		int i;
		float f;
		char c;
		double d;
		std::stringstream ss;
		ss << str;
		ss >> i;
		if (!print_char(str, c, i, f, d) && !print_int(str, c, i, f, d)
			&& !print_float(str, c, i, f, d) && !print_double(str, c, i, f, d))
			throw ("Invalid type !");
	}
	catch (const char* s)
	{
		std::cout << s << std::endl;
	}
	return 0;
}
