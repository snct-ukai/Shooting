#include "Math.h"
#include <stdexcept>

double Math::power(double num, int a) {
	double mul = 1;
	if (num == 0 && a < 0) {
		throw std::logic_error("Uncalculated");
		return -1;
	}
	for (int i = 0; i < (a > 0 ? a : -a); i++) {
		mul *= num;
	}
	return a > 0 ? mul : 1 / mul;
}