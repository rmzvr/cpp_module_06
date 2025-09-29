#include "ScalarConverter.hpp"

bool	isCharacterLiteral(std::string input)
{
	unsigned char	c;
	if (input.length() == 1)
	{
		c = static_cast<unsigned char>(input.at(0));
		if (std::isprint(c) && !std::isdigit(c))
		{
			return true;
		}
	}
	return false;
}

bool	isIntegerLiteral(std::string input)
{
	int			result;
	std::size_t	pos;

	try
	{
		result = std::stoi(input, &pos);
		if (pos == input.length())
		{
			return true;
		}
	}
	catch(const std::exception& e)
	{
		return false;
	}
	return false;
}

bool	isFloatLiteral(std::string input)
{
	float		result;
	std::size_t	pos;

	try
	{
		result = std::stof(input, &pos);
		if (pos + 1 == input.length() && input.at(pos) == 'f')
		{
			return true;
		}
	}
	catch(const std::exception& e)
	{
		return false;
	}
	return false;
}
bool	isDoubleLiteral(std::string input)
{
	double		result;
	std::size_t	pos;

	try
	{
		result = std::stod(input, &pos);
		if (pos == input.length())
		{
			return true;
		}
	}
	catch(const std::exception& e)
	{
		return false;
	}
	return false;
}

void	printCharacterValue( char char_value )
{
	if (std::isprint(char_value))
	{
		std::cout << "char: " << "'" << char_value << "'" << "\n";
	}
	else
	{
		std::cout << "char: Non displayable" << "\n";
	}
}

void	printIntegerValue( int integer_value )
{
	std::cout << "int: " << integer_value << "\n";
}

void	printFloatValue( float float_value )
{
	std::cout << "float: " << std::fixed << std::setprecision(1) << float_value << 'f' << '\n';
}

void	printDoubleValue( double double_value )
{
	std::cout << "double: " << double_value << "\n";
}

unsigned char	convertToCharacter( std::string const & input )
{
	unsigned char	char_value;

	try
	{
		char_value = static_cast<unsigned char>(input.at(0));
	}
	catch(const std::exception& e)
	{
		std::cerr << "convertToCharacter error: " << e.what() << '\n';
	}
	return char_value;
}

int	convertToInteger( std::string const & input )
{
	int	integer_value;

	try
	{
		integer_value = std::stoi(input);
	}
	catch(const std::exception& e)
	{
		std::cerr << "convertToInteger error: " << e.what() << '\n';
	}
	return integer_value;
}

float	convertToFloat( std::string const & input )
{
	float	float_value;

	try
	{
		float_value = std::stof(input);
	}
	catch(const std::exception& e)
	{
		std::cerr << "convertToFloat error: " << e.what() << '\n';
	}
	return float_value;
}

double	convertToDouble( std::string const & input )
{
	double	double_value;

	try
	{
		double_value = std::stod(input);
	}
	catch(const std::exception& e)
	{
		std::cerr << "convertToDouble error: " << e.what() << '\n';
	}
	return double_value;
}

void	handleCharacterLiteral( std::string const & input )
{
	int				integer_value;
	float			float_value;
	double			double_value;
	unsigned char	char_value;

	char_value = convertToCharacter(input);

	integer_value = static_cast<int>(char_value);
	float_value = static_cast<float>(char_value);
	double_value = static_cast<double>(char_value);

	printCharacterValue(char_value);
	printIntegerValue(integer_value);
	printFloatValue(float_value);
	printDoubleValue(double_value);
}

void	handleIntegerLiteral( std::string const & input )
{

	int				integer_value;
	float			float_value;
	double			double_value;
	unsigned char	char_value;

	integer_value = convertToInteger(input);

	char_value = static_cast<unsigned char>(integer_value);
	float_value = static_cast<float>(integer_value);
	double_value = static_cast<double>(integer_value);

	printCharacterValue(char_value);
	printIntegerValue(integer_value);
	printFloatValue(float_value);
	printDoubleValue(double_value);
}

void	handleFloatLiteral( std::string const & input )
{
	int				integer_value;
	float			float_value;
	double			double_value;
	unsigned char	char_value;

	float_value = convertToFloat(input);

	char_value = static_cast<unsigned char>(float_value);
	integer_value = static_cast<int>(float_value);
	double_value = static_cast<double>(float_value);

	printCharacterValue(char_value);

	if (
		std::isnan(float_value) ||
		std::isinf(float_value) ||
		static_cast<double>(float_value) > static_cast<double>(std::numeric_limits<int>::max()) ||
		static_cast<double>(float_value) < static_cast<double>(std::numeric_limits<int>::min())
	)
	{
		std::cout << "int: impossible" << "\n";
	}
	else
	{
		printIntegerValue(integer_value);
	}

	printFloatValue(float_value);
	printDoubleValue(double_value);
}

void	handleDoubleLiteral( std::string const & input )
{
	int				integer_value;
	float			float_value;
	double			double_value;
	unsigned char	char_value;

	double_value = convertToDouble(input);

	char_value = static_cast<unsigned char>(double_value);
	integer_value = static_cast<int>(double_value);
	float_value = static_cast<float>(double_value);

	printCharacterValue(char_value);

	if (
		std::isnan(double_value) ||
		std::isinf(double_value) ||
		double_value > static_cast<double>(std::numeric_limits<int>::max()) ||
		double_value < static_cast<double>(std::numeric_limits<int>::min())
	)
	{
		std::cout << "int: impossible" << "\n";
	}
	else
	{
		printIntegerValue(integer_value);
	}

	printFloatValue(float_value);
	printDoubleValue(double_value);
}

ScalarConverter::Literals	getType( std::string const & input )
{
	if (isIntegerLiteral(input) == true)
	{
		return ScalarConverter::Literals::Integer;
	}
	else if (isFloatLiteral(input) == true)
	{
		return ScalarConverter::Literals::Float;
	}
	else if (isDoubleLiteral(input) == true)
	{
		return ScalarConverter::Literals::Double;
	}
	else if (isCharacterLiteral(input) == true)
	{
		return ScalarConverter::Literals::Character;
	}
	else
	{
		return ScalarConverter::Literals::Unknown;
	}
}

void	ScalarConverter::convert( std::string const & input )
{

	ScalarConverter::Literals	type = getType(input);

	switch (type)
	{
		case ScalarConverter::Literals::Integer:
			std::cout << "Integer\n";
			handleIntegerLiteral(input);
			break;
		case ScalarConverter::Literals::Float:
			std::cout << "Float\n";
			handleFloatLiteral(input);
			break;
		case ScalarConverter::Literals::Double:
			std::cout << "Double\n";
			handleDoubleLiteral(input);
			break;
		case ScalarConverter::Literals::Character:
			std::cout << "Character\n";
			handleCharacterLiteral(input);
			break;
		default:
			std::cout << "Invalid input\n";
			break;
	}
}
