#include "../includes/B.hpp"

bool isB(Base* ptr) {
	return dynamic_cast<B*>(ptr) != NULL;
}

bool isB(Base& ref) {
	try {
		dynamic_cast<B&>(ref);
		return true;
	} catch (const std::bad_cast&) {
		return false;
	}
}