#include <string>
#include <cctype>
#include <iomanip>

#include "ScalarConverter.hpp"

static bool	detect_character(std::string input)
{
	unsigned char	c;
	if (input.length() == 1)
	{
		c = static_cast<unsigned char>(input.at(0));
		if (std::isprint(c))
		{
			if (std::isdigit(c) == false)
			{
				std::cout << "'" << input << "'" << " is printable character!" << '\n';
				return true;
			}
		}
		else
		{
			std::cout << "'" << input << "'" << " is non-printable character!" << '\n';
			return false;
		}
	}
	return false;
}

static bool	detect_integer(std::string input)
{
	int			result;
	std::size_t	pos;

	try
	{
		result = std::stoi(input, &pos);
		std::cout << "Integer input length: " << input.length() << '\n';
		std::cout << "Integer position: " << pos << '\n';
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

static bool	detect_float(std::string input)
{
	float		result;
	std::size_t	pos;

	try
	{
		result = std::stof(input, &pos);
		std::cout << "Float input length: " << input.length() << '\n';
		std::cout << "Float position: " << pos << '\n';
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

static bool	detect_double(std::string input)
{
	double		result;
	std::size_t	pos;

	try
	{
		result = std::stod(input, &pos);
		std::cout << "Double input length: " << input.length() << '\n';
		std::cout << "Double position: " << pos << '\n';
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

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		return 1;
	}
	std::string	input = static_cast<std::string>(argv[1]);
	if (detect_character(input) == true)
	{
		char c = static_cast<unsigned char>(input.at(0));
		ScalarConverter::convert(c)
	}
	else if (detect_integer(input) == true)
	{

	}
	else if (detect_float(input) == true)
	{

	}
	else if (detect_double(input) == true)
	{
		
	}

	// ScalarConverter::convert(argv[1]);
	return 0;
}