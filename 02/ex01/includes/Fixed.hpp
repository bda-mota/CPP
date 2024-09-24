#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

# define GREEN	"\033[92m"
# define RED	"\033[91m"
# define CYAN	"\033[96m"
# define YELLOW	"\033[93m"
# define BLUE	"\033[94m"
# define MAGENT	"\033[95m"
# define RESET	"\033[0m"

class	Fixed {

public:

	Fixed( void );
	Fixed( const Fixed& other );
	~Fixed( void );
	Fixed& operator=( const Fixed& other );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	Fixed( const int intFixedNumber );
	Fixed( const float floatFixedNumber );
	float	toFloat( void ) const;
	int		toInt( void ) const;

private:

	int	_fixedNumberValue;
	static const int	_fractionalBits = 8;

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
