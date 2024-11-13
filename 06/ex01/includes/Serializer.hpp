#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>
# include "Data.hpp"

# define GREEN	"\033[92m"
# define RED	"\033[91m"
# define CYAN	"\033[96m"
# define YELLOW	"\033[93m"
# define BLUE	"\033[94m"
# define MAGENT	"\033[95m"
# define RESET	"\033[0m"

class	Serializer {

private:

	Serializer( void );
	Serializer( const Serializer& other ) ;
	Serializer& operator=( const Serializer& other ) ;
	~Serializer( void );

public:

	static uintptr_t serialize( Data* ptr );
	static Data* deserialize( uintptr_t raw );
};

#endif
