#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(void) {};

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &other): std::stack<T>(other) {};

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &other) {
	if (this != &other) {
		std::stack<T>::operator=(other);
	}
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack(void) {};

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void) {
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void) {
	return this->c.end();
}