#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <iostream>

# define GREEN	"\033[92m"
# define RED	"\033[91m"
# define CYAN	"\033[96m"
# define YELLOW	"\033[93m"
# define BLUE	"\033[94m"
# define MAGENT	"\033[95m"
# define RESET	"\033[0m"

enum Types {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	IMPOSSIBLE,
	NON_DISP
};
class	ScalarConverter {

private:

	ScalarConverter( void );
	ScalarConverter( const ScalarConverter& other );
	ScalarConverter& operator=( const ScalarConverter& other );
	~ScalarConverter( void );

public:

	static void convert( std::string const& data );

};

#endif
