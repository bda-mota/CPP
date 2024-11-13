#ifndef B_HPP
# define B_HPP

# include "Base.hpp"

class B : public Base {};

bool isB(Base* ptr);
bool isB(Base& ref);

#endif