#include "Serializer.hpp"

int	main( void )
{
	Data	data;
	Data *	p_data = &data;
	std::cout << data.a << std::endl;
	uintptr_t p_ui = Serializer::serialize(p_data);
	Serializer::deserialize(p_ui);
	return 0;
}