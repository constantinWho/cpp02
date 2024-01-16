#include "Fixed.hpp"
# include "Point.hpp"

int main ( void ) {
	if ( bsp( Point(46657, 5436897), Point(34654, -546548), Point(20, 0), Point(30, 15) ) == true ) {
		std::cout << "Point is in the triangle" << std::endl;
	} else {
		std::cout << "Point is not in the triangle" << std::endl;
	}
	return 0;
}
