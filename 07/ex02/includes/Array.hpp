#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>
#include <cstddef>
#include <cstdlib>

template <typename T>
class Array{

private:

	T *_array;
	unsigned int _size;

public:

	Array(void);
	Array(unsigned int n);
	Array(const Array &other);
	Array &operator=(const Array &other);
	~Array(void);

	T &operator[](unsigned int index);
	unsigned int size(void) const;

};


#endif