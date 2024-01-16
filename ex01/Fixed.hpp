#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int					_rawBits;
		static const int	_fractBits = 8;
	public:
		Fixed( void );
		Fixed( const int rawBits );
		Fixed( const float rawBits );
		Fixed( const Fixed& other );
		Fixed& operator=( const Fixed& other );
		~Fixed( void );

		float	toFloat( void ) const;
		int		toInt( void ) const;
		void	setRawBits( int const raw );
		int		getRawBits( void ) const;
};

std::ostream& operator<<( std::ostream& o, Fixed const& i );

#endif
