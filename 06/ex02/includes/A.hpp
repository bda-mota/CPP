#ifndef A_HPP
# define A_HPP

# include "Base.hpp"

class A : public Base {};

bool isA(Base* ptr);
bool isA(Base& ref);

#endif
