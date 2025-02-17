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
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	std::map<std::string, float> getData(void) const;
	void	fillReferenceContainer(std::string dataFile);
	void	parsingInputFile(std::string filename);
	float	calculateValue(float referenceRate, float amount);
	int		validateInput(std::string date, std::string amount);
	float	findClosestRate(const std::map<std::string, float> &data, const std::string &date);

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