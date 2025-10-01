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

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
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

bool Fixed::operator>( const Fixed &fixed ) const
{
    return this->_value > fixed._value;
}

bool Fixed::operator<( const Fixed &fixed ) const
{
    return this->_value < fixed._value;
}

bool Fixed::operator>=( const Fixed &fixed ) const
{
    return this->_value >= fixed._value;
}

bool Fixed::operator<=( const Fixed &fixed ) const
{
    return this->_value <= fixed._value;
}

bool Fixed::operator==( const Fixed &fixed ) const
{
    return this->_value == fixed._value;
}

bool Fixed::operator!=( const Fixed &fixed ) const
{
    return this->_value != fixed._value;
}

Fixed Fixed::operator+( const Fixed &fixed ) const
{
    Fixed result;
    result.setRawBits(this->_value + fixed._value);
    return result;
}

Fixed Fixed::operator-( const Fixed &fixed ) const
{
    Fixed result;
    result.setRawBits(this->_value - fixed._value);
    return result;
}

Fixed Fixed::operator*( const Fixed &fixed ) const
{
    Fixed result;
    long temp = (long)this->_value * (long)fixed._value;
    result.setRawBits((int)(temp >> this->_fractionalBits));
    return result;
}

Fixed Fixed::operator/( const Fixed &fixed ) const
{
    Fixed result;
    if (fixed._value == 0)
    {
        std::cerr << "Error: Division by zero" << std::endl;
        return result;
    }
    long temp = ((long)this->_value << this->_fractionalBits) / (long)fixed._value;
    result.setRawBits((int)temp);
    return result;
}

Fixed& Fixed::operator++( void )
{
    this->_value++;
    return *this;
}

Fixed Fixed::operator++( int )
{
    Fixed temp = *this;
    this->_value++;
    return temp;
}

Fixed& Fixed::operator--( void )
{
    this->_value--;
    return *this;
}

Fixed Fixed::operator--( int )
{
    Fixed temp = *this;
    this->_value--;
    return temp;
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

Fixed& Fixed::min( Fixed& a, Fixed& b )
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min( const Fixed& a, const Fixed& b )
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max( Fixed& a, Fixed& b )
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max( const Fixed& a, const Fixed& b )
{
    return (a > b) ? a : b;
}
