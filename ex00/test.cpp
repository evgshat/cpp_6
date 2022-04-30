#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

// Явное преобразование типов
// static_cast : int, char, float, double и.т.д
// reinterpret_cast : каст указателей
// const_cast : каст констант
// dynamic_cast : каст классов
// c-cast (type)val : (int)i

int main()
{
	string str = "4";
	int i;
	float f;
	char c = 42;
	double d;
	stringstream ss;
	ss << str;

// char
	if (str.size() == 1 && !isdigit(str[0]))
	{
		ss >> c;
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
	}
	else
	{
		ss >> i;
		c = static_cast<char>(i);
		f = static_cast<float>(i);
		d = static_cast<double>(i);
	}

// 
	if (isprint(c))
		cout << "char: " << c << endl;
	cout << "char: Non displayable" << std::endl;
	cout << "int: " << i << endl;
	cout << setprecision(1) << fixed;
	cout << "float: " <<  f << 'f' << endl;
	cout << "double: " << d << endl;

	return 0;
}
