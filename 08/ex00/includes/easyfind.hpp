#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <exception>
#include <deque>

template <typename T>
typename T::iterator easyfind(T const &container, int const value) {
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::out_of_range("Value not found in the container");
	return it;					
}

#endif	