#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <iostream>

class ScalarConverter
{
	public:
		ScalarConverter() = delete;
		virtual	~ScalarConverter() = 0;

		static void	convert(char * str);
};

#endif