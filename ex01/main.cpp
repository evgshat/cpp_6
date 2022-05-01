#include <iostream>

typedef struct Data
{
	int s_number;
	std::string s_str;
} t_data;

uintptr_t serialize(Data* ptr)
{
	uintptr_t res;
	res = reinterpret_cast<uintptr_t>(ptr);
	return (res);
}

Data* deserialize(uintptr_t raw)
{
	Data* res;
	res = reinterpret_cast<Data *>(raw);
	return (res);
}

int main()
{
	Data *data = new Data();
	uintptr_t res_ser;
	res_ser = serialize(data);
	Data *data2;
	data2 = deserialize(res_ser);
	if (data == data2)
		std::cout << "It is ok" << std::endl;
	else
		std::cout << "Error" << std::endl;
	delete data;
}
