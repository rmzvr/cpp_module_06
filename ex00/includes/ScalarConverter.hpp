#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <cmath>
# include <cctype>
# include <limits>
# include <iomanip>
# include <iostream>
# include <stdexcept>

class ScalarConverter
{
	private:
		ScalarConverter();
	public:
		static void	convert( std::string const & input );
		enum class Literals
		{
			Character,
			Integer,
			Float,
			Double,
			Unknown
		};
};

ScalarConverter::Literals	getType( std::string const & input );

bool			isCharacterLiteral( std::string input );
bool			isIntegerLiteral( std::string input );
bool			isFloatLiteral( std::string input );
bool			isDoubleLiteral( std::string input );

void			printCharacterValue( char char_value );
void			printIntegerValue( int integer_value );
void			printFloatValue( float float_value );
void			printDoubleValue( double double_value );

unsigned char	convertToCharacter( std::string const & input );
int				convertToInteger( std::string const & input );
float			convertToFloat( std::string const & input );
double			convertToDouble( std::string const & input );

void			handleCharacterLiteral( std::string const & input );
void			handleIntegerLiteral( std::string const & input );
void			handleFloatLiteral( std::string const & input );
void			handleDoubleLiteral( std::string const & input );

#endif