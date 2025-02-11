#include "../includes/Array.hpp"

template <typename T>
Array<T>::Array(void) : _array(NULL), _size(0) {}

	template <typename T>
	Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array &other) : _array(NULL), _size(other._size) {
	if (other._size == 0) {
		_array = NULL;
	}
	else {
		_array = new T[other._size];
		for (unsigned int i = 0; i < other._size; i++)
			_array[i] = other._array[i];
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
	if (this != &other) {
		delete[] _array;

		_size = other._size;
		_array = new T[_size];
		for (unsigned int i = 0; i < other._size; i++) {
			_array[i] = other._array[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array(void) {
	delete[] _array;
}

template <typename T>
T &Array<T>::operator[](unsigned int index) {
	if (index >= _size) {
		throw std::exception();
	}
	return _array[index];
}

template <typename T>
unsigned int Array<T>::size(void) const {
	return _size;
}