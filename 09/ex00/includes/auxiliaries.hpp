#ifndef AUXILIARIES_HPP
# define AUXILIARIES_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <algorithm> 

void	removeSpaces(std::string &str);
void	checkDate(const std::string &date);
void	checkValue(std::string value);
bool	isNumeric(const std::string& str);
bool	isValidDay(ssize_t day, ssize_t month, ssize_t year);
bool	isLeapYear(ssize_t year);


#endif