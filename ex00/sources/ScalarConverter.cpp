#include "ScalarConverter.hpp"

static bool	is_character(std::string input)
{
	unsigned char	c;
	if (input.length() == 1)
	{
		c = static_cast<unsigned char>(input.at(0));
		if (std::isprint(c) && !std::isdigit(c))
		{
			std::cout << "---------------------------" << '\n';
			std::cout << "Character detection result: " << c << '\n';
			std::cout << "---------------------------" << '\n';
			return true;
		}
		else
		{
			std::cout << "Character detection error: " << "'" << input << "'" << " is non-printable character!" << '\n';
			return false;
		}
	}
	return false;
}

static bool	is_integer(std::string input)
{
	int			result;
	std::size_t	pos;

	try
	{
		result = std::stoi(input, &pos);
		if (pos == input.length())
		{
			std::cout << "---------------------------" << '\n';
			std::cout << "Integer detection result: " << result << '\n';
			std::cout << "---------------------------" << '\n';
			return true;
		}
		return false;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Integer detection error: " << e.what() << '\n';
		return false;
	}
	return false;
}

static bool	is_float(std::string input)
{
	float		result;
	std::size_t	pos;

	try
	{
		result = std::stof(input, &pos);
		if (pos + 1 == input.length() && input.at(pos) == 'f')
		{
			std::cout << "---------------------------" << '\n';
			std::cout << "Float detection result: " << std::fixed << std::setprecision(1) << result << 'f' << '\n';
			std::cout << "---------------------------" << '\n';
			return true;
		}
		return false;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Float detection error: " << e.what() << '\n';
		return false;
	}
	return false;
}
static bool	is_double(std::string input)
{
	double		result;
	std::size_t	pos;

	try
	{
		result = std::stod(input, &pos);
		if (pos == input.length())
		{
			std::cout << "---------------------------" << '\n';
			std::cout << "Double detection result: " << std::fixed << std::setprecision(1) << result << '\n';
			std::cout << "---------------------------" << '\n';
			return true;
		}
		return false;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Double detection error: " << e.what() << '\n';
		return false;
	}
	return false;
}

static ScalarConverter::Types	getType( std::string const & input )
{
	if (is_integer(input) == true)
	{
		return ScalarConverter::Types::Integer;
	}
	else if (is_float(input) == true)
	{
		return ScalarConverter::Types::Float;
	}
	else if (is_double(input) == true)
	{
		return ScalarConverter::Types::Double;
	}
	else if (is_character(input) == true)
	{
		return ScalarConverter::Types::Character;
	}
	else
	{
		return ScalarConverter::Types::Unknown;
	}
}

static int	convertToInteger( std::string const & input )
{
	int	i;

	try
	{
		i = std::stoi(input);
	}
	catch(const std::exception& e)
	{
		std::cerr << "convertToInteger error: " << e.what() << '\n';
	}
	return i;
}

static float	convertToFloat( std::string const & input )
{
	float	f;

	try
	{
		f = std::stof(input);
	}
	catch(const std::exception& e)
	{
		std::cerr << "convertToFloat error: " << e.what() << '\n';
	}
	return f;
}

static double	convertToDouble( std::string const & input )
{
	double	d;

	try
	{
		d = std::stod(input);
	}
	catch(const std::exception& e)
	{
		std::cerr << "convertToDouble error: " << e.what() << '\n';
	}
	return d;
}

static unsigned char	convertToCharacter( std::string const & input )
{
	unsigned char	c;

	try
	{
		c = static_cast<unsigned char>(input.at(0));
	}
	catch(const std::exception& e)
	{
		std::cerr << "convertToCharacter error: " << e.what() << '\n';
	}
	return c;
}

static void	characterConversionToOtherTypes( unsigned char c )
{
	int				i;
	float			f;
	double			d;

	i = static_cast<int>(c);
	f = static_cast<float>(c);
	d = static_cast<double>(c);

	std::cout << "char: " << "'" << c << "'" << "\n";
	std::cout << "int: " << i << "\n";
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << 'f' << '\n';
	std::cout << "double: " << d << "\n";
}

static void	integerConversionToOtherTypes( int i )
{
	float			f;
	double			d;
	unsigned char	c;

	i = static_cast<int>(i);
	f = static_cast<float>(i);
	d = static_cast<double>(i);
	c = static_cast<unsigned char>(i);

	if (std::isprint(c))
	{
		std::cout << "char: " << "'" << c << "'" << "\n";
	}
	else
	{
		std::cout << "char: Non displayable" << "\n";
	}

	std::cout << "int: " << i << "\n";
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << 'f' << '\n';
	std::cout << "double: " << d << "\n";
}

static void	floatConversionToOtherTypes( float f )
{
	int				i;
	double			d;
	unsigned char	c;

	if (std::numeric_limits<int>::max() >= f)
	{
		i = static_cast<int>(f);
	}
	d = static_cast<double>(f);
	c = static_cast<unsigned char>(f);

	if (std::isprint(c))
	{
		std::cout << "char: " << "'" << c << "'" << "\n";
	}
	else
	{
		std::cout << "char: Non displayable" << "\n";
	}

	if (std::numeric_limits<int>::max() > f)
	{
		std::cout << "int: " << i << "\n";
	}
	else
	{
		std::cout << "int: impossible" << "\n";
	}

	std::cout << "float: " << std::fixed << std::setprecision(1) << f << 'f' << '\n';
	std::cout << "double: " << d << "\n";
}

static void	doubleConversionToOtherTypes( double d )
{
	int				i;
	float			f;
	unsigned char	c;

	f = static_cast<float>(d);
	c = static_cast<unsigned char>(d);

	if (std::isprint(c))
	{
		std::cout << "char: " << "'" << c << "'" << "\n";
	}
	else
	{
		std::cout << "char: Non displayable" << "\n";
	}
	if (
		(d > 0 && d - std::numeric_limits<int>::max() < 1)
		|| (d < 0 && d - std::numeric_limits<int>::min() <= 0 && d - std::numeric_limits<int>::min() > -1))
	{
		i = static_cast<int>(d);
		std::cout << "int: " << i << "\n";
	}
	else
	{
		std::cout << "int: impossible" << "\n";
	}

	std::cout << "float: " << std::fixed << std::setprecision(1) << f << 'f' << '\n';
	std::cout << "double: " << d << "\n";
}

void	ScalarConverter::convert( std::string const & input )
{
	int				i;
	float			f;
	double			d;
	unsigned char	c;

	(void) i;
	(void) f;
	(void) d;
	(void) c;
	ScalarConverter::Types	type = getType(input);

	switch (type)
	{
		case ScalarConverter::Types::Integer:
			std::cout << "Integer\n";
			i = convertToInteger(input);
			integerConversionToOtherTypes(i);
			break;
		case ScalarConverter::Types::Float:
			std::cout << "Float\n";
			f = convertToFloat(input);
			floatConversionToOtherTypes(f);
			break;
		case ScalarConverter::Types::Double:
			std::cout << "Double\n";
			d = convertToDouble(input);
			doubleConversionToOtherTypes(d);
			break;
		case ScalarConverter::Types::Character:
			std::cout << "Character\n";
			c = convertToCharacter(input);
			characterConversionToOtherTypes(c);
			break;
		default:
			std::cout << "Unknown\n";
			break;
	}
}
