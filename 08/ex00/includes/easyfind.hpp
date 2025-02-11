#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <exception>
#include <algorithm> 
#include <deque>

template <typename T>
typename T::const_iterator easyfind(T const &container, int const value) {
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::out_of_range("Value not found in the container");
	return it;					
}

#endif	