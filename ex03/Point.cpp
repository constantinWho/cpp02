#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0) {}

Point::Point( float x, float y) : _x(x), _y(y) {}

Point::Point( const Point& other) { *this = other; }

Point& Point::operator=( const Point& other) {
	if (this != &other)
	{
		(Fixed)this->_x = other.getX();
		(Fixed)this->_y = other.getY();
	}
	return *this;
}

Point::~Point( void ) {}

Fixed Point::getX( void ) const { return this->_x; }

Fixed Point::getY( void ) const { return this->_y; }

