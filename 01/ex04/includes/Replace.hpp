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
	std::string	filename;
	std::string	s1;
	std::string	s2;

};


#endif
