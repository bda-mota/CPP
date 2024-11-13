#include "../includes/A.hpp"

bool isA(Base* ptr) {
	return dynamic_cast<A*>(ptr) != NULL;
}

bool isA(Base& ref) {
	try {
		dynamic_cast<A&>(ref);
		return true;
	} catch (const std::bad_cast&) {
		return false;
	}
}