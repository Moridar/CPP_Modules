#include "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed b( 10000 );
a = Fixed( 1234.4321f );

std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
if (a > b)
	std::cout << "a is bigger than b: " << std::endl;
else
	std::cout << "b is bigger than a" << std::endl;

a = 1.5f;
std::cout << "a is " << a << std::endl;
std::cout << "++a is " << ++a << std::endl;
a++;
std::cout << "a++, a is " << a++ << std::endl;
std::cout << "a++ is " << a << std::endl;

a = Fixed(35);
b = Fixed(0.5f);

std::cout << "a to int: " << a.toInt() << std::endl;
std::cout << "a.toFloat(): " << a.toFloat() << std::endl;
std::cout << "b to int: " << b.toInt() << std::endl;
std::cout << "b.toFloat(): " << b.toFloat() << std::endl;
std::cout << "a / b = " << a << " / " << b << " = " << a / b << std::endl;
std::cout << "a + b = " << a << " + " << b << " = " << a + b << std::endl;
std::cout << "a - b = " << a << " - " << b << " = " << a - b << std::endl;
std::cout << "a * b = " << a << " * " << b << " = " << a * b << std::endl;

Fixed c (a * b);
std::cout << "Fixed c (a * b): " << c << std::endl;

std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;
return 0;
}
