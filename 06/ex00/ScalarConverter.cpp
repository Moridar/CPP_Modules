#include "ScalarConverter.hpp"

static char getType(std::string str)
{
	int dot = 0;
	
	if (str.length() == 1 && !isdigit(str[0]))
		return ('c');
	int i = str[0] == '-' || str[0] == '+' ? 1 : 0;
	while (isdigit(str[i]) || str[i] == '.')
		dot += str.at(i++) == '.';
	if (dot > 1)
		throw std::invalid_argument("Impossible type: Multiple decimal points");
	if (std::tolower(str[i]) == 'f' && str[i + 1] == 0)
		return ('f');
	if (str[i] && !isdigit(str[i]) && str[i] != '.')
		throw std::invalid_argument("Impossible type: Invalid character in string");
	return (dot ? 'd' : 'i');
}

static void print(char c, int i, float f, double d)
{
	std::cout << "char: " << (std::isinf(d) || std::isnan(d) ? "Impossible"
		: (isprint(c) ? &c : "Non displayable")) << std::endl;	
	std::cout << "int: " << (std::isinf(d) || std::isnan(d) ? "Impossible"
		: d < INT32_MIN || d > INT32_MAX ? "Overflow" : std::to_string(i)) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(std::string str)
{
	char	c = 0;
	int		i = 0;
	float	f;
	double	d;
	
	f = d = str == "nan" || str == "nanf" ? NAN
		: str == "inf" || str == "+inf" || str == "inff" || str == "+inff" ? INFINITY
		: str == "-inff" || str == "-inf" ? -INFINITY : 0;
	try
	{
		char type = d == 0 ? getType(str) : 0;
		if (type == 'c')
		{
			c = str.at(0);
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
		}
		if (type == 'd')
		{
			try
			{
				d = std::stod(str);
				c = static_cast<char>(d);
				i = static_cast<int>(d);
				f = static_cast<float>(d);
			}
			catch(const std::exception& e)
			{
				throw std::runtime_error("Double overflows");
			}
		}
		if (type == 'f')
		{
			try
			{
				f = std::stof(str);
				c = static_cast<char>(f);
				i = static_cast<int>(f);
				d = static_cast<double>(f);
			}
			catch(const std::exception& e)
			{
				throw std::runtime_error("Float overflows");
			}
		}
		if (type == 'i')
		{
			try
			{
				i = std::stoi(str);
				c = static_cast<char>(i);
				f = static_cast<float>(i);
				d = static_cast<double>(i);
			}
			catch(const std::exception& e)
			{
				throw std::runtime_error("Integer overflows");
			}		
		}
	}
	catch(const std::exception& e)
	{
		return (std::cerr << e.what() << std::endl, void());
	}
	print(c, i, f, d);
}