#ifndef C_HPP
# define C_HPP

# include "Base.hpp"

class C : public Base {};

bool isC(Base* ptr);
bool isC(Base& ref);

#endif