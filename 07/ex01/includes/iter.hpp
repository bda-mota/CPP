#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, int length, void (*func)(T&)) {
	if (array == NULL || func == NULL) {
		return ;
	}
	for (int i = 0; i < length; i++) {
		func(array[i]);
	}
}

template <typename T>
void iter(T const *array, int length, void (*func)(T const&)) {
	if (array == NULL || func == NULL) {
		return ;
	}
	for (int i = 0; i < length; i++) {
		func(array[i]);
	}
}

template <typename T>
void print(T const &elem)
{
    std::cout << elem << " ";
}

template <typename T>
void increment(T &elem)
{
    ++elem;
}

#endif