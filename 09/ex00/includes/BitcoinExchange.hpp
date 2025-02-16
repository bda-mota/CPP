#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <string>
# include <exception>
# include <cstdlib> 

class BitcoinExchange {

private:
	std::map<std::string, float> _data;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	void	fillReferenceContainer(std::string dataFile);
	void	parsingInputFile(std::string filename);
	float	calculateValue(float referenceRate, float amount);

	class InvalidReferenceData : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class InvalidReferenceHeader : public std::exception {
	public:
		virtual const char* what() const throw();
	};

		class InvalidInputData : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class InvalidInputHeader : public std::exception {
	public:
		virtual const char* what() const throw();
	};

};

# include "./auxiliaries.hpp"

#endif