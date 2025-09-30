#include "Base.hpp"

int	main( void )
{
	Base *randomInstance = generate();
	identify(randomInstance);
	identify(*randomInstance);
	return 0;
}