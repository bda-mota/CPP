#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _data(other._data) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	_data = other._data;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::map<std::string, float> BitcoinExchange::getData(void) const { return _data; }

// METHODS

void BitcoinExchange::fillReferenceContainer(std::string dataFile) {
	std::string line;
	std::ifstream file(dataFile.c_str());

	if (!file.is_open()) {
		throw std::invalid_argument("could not open file " + dataFile);		
	}

	std::getline(file, line);
	removeSpaces(line);
	if (line != "date,exchange_rate") {
		throw InvalidReferenceHeader();
	}

	while (std::getline(file, line)) {		
		size_t pos = line.find(',');
		if (pos == std::string::npos) {
			throw InvalidReferenceData();
		}
		std::string date = line.substr(0, pos);
		std::string rate = line.substr(pos + 1);

		removeSpaces(date);
		removeSpaces(rate);
		_data[date] = atof(rate.c_str());
	}

	file.close();
}

void BitcoinExchange::parsingInputFile(std::string filename) {
	std::string line;
	std::ifstream file(filename.c_str());

	if (!file.is_open()) {
		std::cerr << "Error: could not open file " << filename << std::endl;
	}

	std::getline(file, line);
	removeSpaces(line);
	if (line != "date | value") {
		throw InvalidInputHeader();
	}

	while (std::getline(file, line)) {
		if (line.empty()) {
			std::cout << "Error: bad input => empty line." << line << std::endl;
			continue;
		}

		size_t pos = line.find('|');	
		if (pos == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, pos);
		std::string amount = line.substr(pos + 1);
		removeSpaces(date);
		removeSpaces(amount);
		if (validateInput(date, amount)) {
			continue;
		}

		float referenceRate = findClosestRate(_data, date);
		float amountValue = atof(amount.c_str());
		std::cout << date << " => " << amountValue << " = " << amountValue * referenceRate << std::endl;
	}

	file.close();
}

int	BitcoinExchange::validateInput(std::string date, std::string amount) {	
	try {
		checkValue(amount);
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
		return 1;
	}
	try {
		checkDate(date);
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}

float	BitcoinExchange::findClosestRate(const std::map<std::string, float> &data, const std::string &date) {
    std::map<std::string, float>::const_iterator it = data.lower_bound(date);

    if (it != data.end() && it->first == date) {
        return it->second;
    }

    if (it != data.begin()) {
        --it;
        return it->second;
    }
	return it->second;
}

// EXCEPTIONS

const char* BitcoinExchange::InvalidReferenceData::what() const throw() {
	return "Invalid reference data.";
}

const char* BitcoinExchange::InvalidReferenceHeader::what() const throw() {
	return "Invalid header, must be: date,exchange_rate";
}

const char* BitcoinExchange::InvalidInputData::what() const throw() {
	return "Invalid input data, must be: year-month-day | value";
}

const char* BitcoinExchange::InvalidInputHeader::what() const throw() {
	return "Invalid header, must be: date | value";
}