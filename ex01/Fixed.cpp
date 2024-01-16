#include "Fixed.hpp"

Fixed::Fixed( void ) : _rawBits((0 << this->_fractBits)) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int value ) : _rawBits( value << _fractBits ) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float value ) : _rawBits(roundf(value * ( 1 << _fractBits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& other ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=( const Fixed& other ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_rawBits = other.getRawBits();
	return *this;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits( void ) const {
	return this->_rawBits;
}

void	Fixed::setRawBits( int const raw ) {
	this->_rawBits = raw;
}

float	Fixed::toFloat( void ) const {
	return static_cast<float>( this->getRawBits() ) / ( 1 << _fractBits );
}

int		Fixed::toInt( void ) const {
	return this->_rawBits >> _fractBits;
}

std::ostream& operator<<( std::ostream& o, Fixed const& i ) {
	o << i.toFloat();
	return o;
}
