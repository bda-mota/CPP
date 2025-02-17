#include "../includes/auxiliaries.hpp"

void checkValue(std::string value) {
	float val;

	std::istringstream iss(value);
	iss >> val;
	if (iss.fail() || !iss.eof())
		throw std::runtime_error("value is invalid.");
	if (val < 0)
		throw std::runtime_error("not a positive number.");
	if (val > 1000)
		throw std::runtime_error("too large a number.");
}

void checkDate(const std::string &date) {
	std::ostringstream oss;

	if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
		throw std::invalid_argument("Invalid date format.");
	}

	if (!isNumeric(date.substr(0, 4)) || !isNumeric(date.substr(5, 2)) || !isNumeric(date.substr(8, 2))) {
		throw std::invalid_argument("Invalid date format.");
	}
	
	int year = std::atoi((date.substr(0, 4)).c_str());
	int month = std::atoi((date.substr(5, 2)).c_str());
	int day = std::atoi((date.substr(8, 2)).c_str());

	if (year < 1) {
		oss << year;
		throw std::invalid_argument("Invalid year: " + oss.str());
	}
	if (month < 1 || month > 12) {
		oss << month;
		throw std::invalid_argument("Invalid month: " + oss.str());
	}
	if (!isValidDay(day, month, year)) {
		oss << day;
		throw std::invalid_argument("Invalid day: " + oss.str());
	}
}

void removeSpaces(std::string &str) {
	size_t start = str.find_first_not_of(" \t");
	size_t end = str.find_last_not_of(" \t");

	if (start != std::string::npos && end != std::string::npos)
		str = str.substr(start, end - start + 1);
	else if (start != std::string::npos)
		str = str.substr(start);
	else if (end != std::string::npos)
		str = str.substr(0, end + 1);
}

bool isNumeric(const std::string& str) {
	for (size_t i = 0; i < str.size(); i++) {
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool isLeapYear(ssize_t year) {
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool isValidDay(ssize_t day, ssize_t month, ssize_t year) {
	if (day < 1 || day > 31)
		return (false);

	if (month == 4 || month == 6 || month == 9 || month == 11)
		return (day <= 30);
	if (month == 2)
		return (day <= (isLeapYear(year) ? 29 : 28));
	return (day <= 31);
}
