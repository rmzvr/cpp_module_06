#include "Serializer.hpp"

int	main( void )
{
	Data	data;
	Data *	p1_data = &data;
	std::cout << "data.a => " << p1_data->a << ", data address => " << p1_data << ", p1_data address => " << &p1_data << std::endl;
	uintptr_t p_ui = Serializer::serialize(p1_data);
	std::cout << "integer representation of data pointer => " << p_ui << std::endl;
	Data *	p2_data = Serializer::deserialize(p_ui);
	p2_data->a = 2;
	std::cout << "data.a => " << p1_data->a << ", data address => " << p1_data << ", p1_data address => " << &p1_data << std::endl;
	std::cout << "data.a => " << p2_data->a << ", data address => " << p2_data << ", p2_data address => " << &p2_data << std::endl;
	return 0;
}