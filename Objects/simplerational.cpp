#include <iostream>
#include <cstdlib>

class SimpleRational {
private:
	int numerator;
	int denominator;

public:
	// Initializes the components of a Rational Object
	SimpleRational(int n, int d) : numerator(n), denominator(d) {
		if (d == 0) {
			// Display error message
			std::cout << "Zero denominator error\n";
			exit(1);
		}
	}

	SimpleRational() : numerator(0), denominator(1) {}

	void set_numerator(int n) {
		numerator = n;
	}

	void set_denominator(int d) {
		if (d != 0) {
			denominator = d;
		}
		else {
			// Display error message
			std::cout << "Zero denominator error\n";
			exit(1);
		}
	}


	int get_numerator() {
		return numerator;
	}

	int get_denominator() {
		return denominator;
	}

};

SimpleRational multiply(SimpleRational f1, SimpleRational f2) {
	return {
		f1.get_numerator() * f2.get_numerator(),
		f1.get_denominator() * f2.get_denominator()
	};
}

void print_fraction(SimpleRational f) {
	std::cout << f.get_numerator() << '/' << f.get_denominator();
}

int main() {

	SimpleRational fract(1, 2);
	std::cout << "The fraction is: ";
	print_fraction(fract);
	std::cout << '\n';

	fract.set_numerator(19);
	fract.set_denominator(4);
	std::cout << "The fraction now is: ";
	print_fraction(fract);
	std::cout << '\n';

	// Alternate syntax uses {} with constructor instead of ()
	SimpleRational fract1{1,2}, fract2{3,4};
	SimpleRational product = multiply(fract1, fract2);
	std::cout << "The product of ";
	print_fraction(fract1);
	std::cout << " and ";
	print_fraction(fract2);
	std::cout << " is ";
	print_fraction(product);
	std::cout << '\n';

	return 0;
}