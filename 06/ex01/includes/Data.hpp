#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <stdint.h>

class	Data {

private:

	uint32_t	_data;

public:

	Data( void );
	Data( const Data& other );
	Data& operator=( const Data& other );
	~Data( void );

	uint32_t	getData( void );
};

#endif
