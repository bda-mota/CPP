#include "../includes/C.hpp"

bool isC(Base* ptr) {
	return dynamic_cast<C*>(ptr) != NULL;
}

bool isC(Base& ref) {
	try {
		dynamic_cast<C&>(ref);
		return true;
	} catch (const std::bad_cast&) {
		return false;
	}
}