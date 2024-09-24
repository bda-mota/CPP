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
	Fixed( const int intFixedNumber );
	Fixed( const float floatFixedNumber );
	Fixed( const Fixed& other );
	~Fixed( void );

	Fixed& operator=( const Fixed& other );
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

	//Assignment operator

	//Aritmetic operators
	Fixed	operator+(const Fixed& other) const;
	Fixed	operator-(const Fixed& other) const;
	Fixed	operator/(const Fixed& other) const;
	Fixed	operator*(const Fixed& other) const;

	//Comparison operators
	bool	operator==(const Fixed& other) const;
	bool	operator!=(const Fixed& other) const;
	bool	operator<=(const Fixed& other) const;
	bool	operator>=(const Fixed& other) const;
	bool	operator<(const Fixed& other) const;
	bool	operator>(const Fixed& other) const;

	//Others operators
	Fixed&	operator++(); // ++a
	Fixed	operator++(int); // a++
	Fixed&	operator--(); // --a
	Fixed	operator--(int); // a--

	//Min
	static Fixed& min( Fixed& a, Fixed& b );
	static const Fixed& min( const Fixed& a,  const Fixed& b);

	//Max
	static Fixed& max( Fixed& a, Fixed& b );
	static const Fixed& max( const Fixed& a,  const Fixed& b);

private:

	int	_fixedNumberValue;
	static const int	_fractionalBits = 8;

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
