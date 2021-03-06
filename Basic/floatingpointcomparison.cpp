#include <iostream>

/*
 * Floating-point comparison
**/

bool equals(double a, double b, double tolerance) {
	return (a == b) || (fabs(a - b) < tolerance);
}

int main() {

	for (double i = 0.0; !equals(i,1.0, 0.0001); i += 0.1) {
		std::cout << i << '\n';
	}
	return 0;
}

