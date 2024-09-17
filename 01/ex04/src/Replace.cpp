#include "../includes/Replace.hpp"

Replace::Replace() {}

Replace::Replace(std::string filename, std::string s1, std::string s2) : _filename(filename), _s1(s1), _s2(s2) {}

Replace::~Replace() {}

std::string	Replace::getFilename() const { return _filename; }

std::string	Replace::getS1() const { return _s1; }

std::string	Replace::getS2() const { return _s2; }
