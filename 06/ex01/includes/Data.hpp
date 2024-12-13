#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <stdint.h>

class	Data {

private:

	std::string	_name;
	uint32_t	_value;

public:

	Data(void);
	Data(std::string name, uint32_t value);
	Data(const Data& other);
	Data& operator=(const Data& other);
	~Data(void);

	std::string getName(void) const;
	uint32_t	getValue(void) const;

};

std::ostream& operator<<( std::ostream& os, const Data& data );


#endif
