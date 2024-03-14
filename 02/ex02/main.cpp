#include "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed const b( 10000 );
Fixed const c( 42.42f );
Fixed const d( b );
a = Fixed( 1234.4321f );

std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
if (a > b)
	std::cout << "a is bigger than b: " << std::endl;
else
	std::cout << "b is bigger than a" << std::endl;

return 0;
}
