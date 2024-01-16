#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int					_value;
		static const int	_fractBits = 8;
	public:
		Fixed( void );
		Fixed( const Fixed& other );
		Fixed& operator=( const Fixed& other );
		~Fixed( void );

		void	setRawBits( int const raw );
		int		getRawBits( void ) const;
};

#endif
