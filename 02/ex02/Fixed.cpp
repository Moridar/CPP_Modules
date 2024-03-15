#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = value << _fractionalBits;

}
	
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignation operator called" << std::endl;
	_fixedPointValue = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return _fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	_fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
	return (float)_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return _fixedPointValue >> _fractionalBits;
}

bool Fixed::operator>(const Fixed &other)
{
	return _fixedPointValue > other.getRawBits();
};
bool Fixed::operator<(const Fixed &other)
{
	return _fixedPointValue < other.getRawBits();
};
bool Fixed::operator>=(const Fixed &other)
{
	return _fixedPointValue >= other.getRawBits();
};

bool Fixed::operator<=(const Fixed &other)
{
	return _fixedPointValue <= other.getRawBits();
};

bool Fixed::operator==(const Fixed &other)
{
	return _fixedPointValue == other.getRawBits();
};

bool Fixed::operator!=(const Fixed &other)
{
	return _fixedPointValue != other.getRawBits();
};

Fixed Fixed::operator+(const Fixed &other)
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other)
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other)
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other)
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed& Fixed::operator++( void )
{
	this->_fixedPointValue++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++*this;
	return (temp);
}

Fixed& Fixed::operator--( void )
{
	_fixedPointValue--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--*this;
	return (temp);
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}