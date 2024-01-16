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

		float				toFloat( void ) const;
		int					toInt( void ) const;
		void				setRawBits( int const raw );
		int					getRawBits( void ) const;

		bool				operator>( const Fixed& other ) const ;
		bool				operator<( const Fixed& other ) const ;
		bool				operator>=( const Fixed& other ) const ;
		bool				operator<=( const Fixed& other ) const ;
		bool				operator==( const Fixed& other ) const ;
		bool				operator!=( const Fixed& other ) const ;

		Fixed				operator+( const Fixed& other ) const ;
		Fixed				operator-( const Fixed& other ) const ;
		Fixed				operator*( const Fixed& other ) const ;
		Fixed				operator/( const Fixed& other ) const ;

		Fixed				operator++( void );
		Fixed				operator++( int );
		Fixed				operator--( void );
		Fixed				operator--( int );

		static Fixed&		min( Fixed& a, Fixed& b );
		static const Fixed&	min( const Fixed& a, const Fixed& b );
		static Fixed&		max( Fixed& a, Fixed& b );
		static const Fixed&	max( const Fixed& a, const Fixed& b );
};

std::ostream& operator<<( std::ostream& o, Fixed const& i );

#endif
