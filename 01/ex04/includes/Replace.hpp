#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>

class	Replace {

public:
	Replace();
	Replace(std::string filename, std::string s1, std::string s2);
	~Replace();

	std::string	getFilename() const;
	std::string	getS1() const;
	std::string	getS2() const;

private:
	std::string	_filename;
	std::string	_s1;
	std::string	_s2;

};


#endif
