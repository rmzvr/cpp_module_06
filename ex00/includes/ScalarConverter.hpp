#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <cctype>
# include <limits>
# include <iomanip>
# include <iostream>
class ScalarConverter
{
	private:
		ScalarConverter();
	public:
		static void	convert( std::string const & input );
		enum class Types
		{
			Character,
			Integer,
			Float,
			Double,
			Unknown
		};
};

#endif