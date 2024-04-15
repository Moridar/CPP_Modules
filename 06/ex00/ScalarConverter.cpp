#include "ScalarConverter.hpp"
#include <cmath>

static char getType(std::string str)
{
	int i = 0;
	int dot = 0;

	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str.at(i) == '.')
		{
			if (++dot > 1)
				return (0);
		}
		else if (!isdigit(str.at(i)))
		{
			if (str.at(i) == 'f' && i == (int) str.length() - 1 && dot == 1)
			    return ('f');
			return (0);
		}	
		i++;
	}
	if (!dot)
		return ('i');
	return ('d');
}

static void printc(char c)
{
	if (isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

static void printnan()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

static void printinf()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: inff" << std::endl;
	std::cout << "double: inf" << std::endl;
}

static void printneginf()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: -inff" << std::endl;
	std::cout << "double: -inf" << std::endl;
}
static void print(char c)
{
	printc(c);
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}
static void print(int i)
{
	printc(static_cast<char>(i));
	std::cout << "int: " << static_cast<int>(i) << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}
static void print(double d)
{
	if (std::isnan(d))
		return (printnan());
	if (std::isinf(d))
	{
		if (std::signbit(d))
			return (printneginf());
		return (printinf());
	}
	printc(static_cast<char>(d));
	if (d > INT32_MAX || d < INT32_MIN)
		std::cout << "int: overflows" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(d) << std::endl;
}

static void print(float f)
{
	print((double) f);
}
void ScalarConverter::convert(std::string str)
{
	if (str == "nan" || str == "inf" || str == "+inf" || str == "-inf")
	{
		double d;
		if (str == "nan")
			d = NAN;
		else if (str == "-inf")
			d = -INFINITY;
		else
			d = INFINITY;
		print(d);
		return ;
	}
	if (str == "nanf" || str == "inff" || str == "+inff" || str == "-inff")
	{
		float f;
		if (str == "nanf")
			f = NAN;
		else if (str == "-inff")
			f = -INFINITY;
		else
			f = INFINITY;
		print(f);
		return ;
	}
	if (str.length() == 1 && !isdigit(str[0]))
	{
		print(str.at(0));
		return ;
	}
	char type = getType(str);
	if (type == 0)
		std::cout << "Impossible type" << std::endl;
	if (type == 'd')
	{
		try
		{
			print(std::stod(str));
		}
		catch(const std::exception& e)
		{
			std::cerr << "Double overflows" << std::endl;
		}
	}
	if (type == 'f')
	{
		try
		{
			print(std::stof(str));
		}
		catch(const std::exception& e)
		{
			std::cerr << "Float overflows" << std::endl;
		}
	}
	if (type == 'i')
	{
		try
		{
			print(std::stoi(str));
		}
		catch(const std::exception& e)
		{
			std::cerr << "Integer overflows" << '\n';
		}		
	}
}