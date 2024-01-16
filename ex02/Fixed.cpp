#include "Fixed.hpp"

Fixed::Fixed( void ) : _rawBits((0 << this->_fractBits)) {}

Fixed::Fixed( const int value ) : _rawBits( value << _fractBits ) {}

Fixed::Fixed( const float value ) : _rawBits(roundf(value * ( 1 << _fractBits))) {}

Fixed::Fixed( const Fixed& other ) { *this = other; }

Fixed&	Fixed::operator=( const Fixed& other ) {
	if (this != &other)
		this->_rawBits = other.getRawBits();
	return *this;
}

Fixed::~Fixed( void ) {}

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

bool	Fixed::operator>( const Fixed& other ) const {
	return this->getRawBits() > other.getRawBits();
}

bool	Fixed::operator<( const Fixed& other ) const {
	return this->getRawBits() < other.getRawBits();
}

bool	Fixed::operator>=( const Fixed& other ) const {
	return this->getRawBits() >= other.getRawBits();
}

bool	Fixed::operator<=( const Fixed& other ) const {
	return this->getRawBits() <= other.getRawBits();
}

bool	Fixed::operator==( const Fixed& other ) const {
	return this->getRawBits() == other.getRawBits();
}

bool	Fixed::operator!=( const Fixed& other ) const {
	return this->getRawBits() != other.getRawBits();
}

Fixed	Fixed::operator+( const Fixed& other ) const {
	return Fixed( this->toFloat() + other.toFloat() );
}

Fixed	Fixed::operator-( const Fixed& other ) const {
	return Fixed( this->toFloat() - other.toFloat() );
}

Fixed	Fixed::operator*( const Fixed& other ) const {
	return Fixed( this->toFloat() * other.toFloat() );
}

Fixed	Fixed::operator/( const Fixed& other ) const {
	return Fixed( this->toFloat() / other.toFloat() );
}


Fixed	Fixed::operator++( void ) {
	++this->_rawBits;
	return *this;
}

Fixed	Fixed::operator++( int ) {
	Fixed tmp( *this );
	tmp._rawBits = this->_rawBits++;
	return tmp;
}

Fixed	Fixed::operator--( void ) {
	--this->_rawBits;
	return *this;
}

Fixed	Fixed::operator--( int ) {
	Fixed tmp( *this );
	tmp._rawBits = this->_rawBits--;
	return tmp;
}

Fixed&	Fixed::min( Fixed &a, Fixed &b ) {
	if ( a.getRawBits() < b.getRawBits() )
		return a;
	return b;
}

const	Fixed& Fixed::min( const Fixed &a, const Fixed &b ) {
	if ( a.getRawBits() < b.getRawBits() )
		return a;
	return b;
}

Fixed&	Fixed::max( Fixed &a, Fixed &b ) {
	if ( a.getRawBits() > b.getRawBits() )
		return a;
	return b;
}

const	Fixed& Fixed::max( const Fixed &a, const Fixed &b ) {
	if ( a.getRawBits() > b.getRawBits() )
		return a;
	return b;
}
