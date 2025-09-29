#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <cstdint>
# include <iostream>

struct Data
{
	int a = 0;
	int b = 1;
};

class Serializer
{
	private:
		Serializer();
	public:
		static uintptr_t	serialize( Data* ptr );
		static Data*		deserialize( uintptr_t raw );
};

#endif