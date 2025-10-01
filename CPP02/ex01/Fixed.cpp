#include "Fixed.hpp"


Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->_value = 0;
}

Fixed::Fixed( const Fixed &src )
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::Fixed( const int value )
{
    std::cout << "Int constructor called" << std::endl;
    this->_value = value << this->_fractionalBits;
}

Fixed::Fixed( const float value )
{
    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(value * (1 << this->_fractionalBits));
}

Fixed& Fixed::operator=( const Fixed &src )
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
        this->_value = src.getRawBits();
    return *this;
}

std::ostream& operator<<( std::ostream &out, const Fixed &fixed )
{
    out << fixed.toFloat();
    return out;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits( int const raw )
{
    this->_value = raw;
}

float Fixed::toFloat( void ) const
{
    return (float)this->_value / (1 << this->_fractionalBits);
}

int Fixed::toInt( void ) const
{
    return roundf(this->_value >> this->_fractionalBits);
}