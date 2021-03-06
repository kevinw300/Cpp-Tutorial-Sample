#include "stdafx.h"

#include <iostream>

class Rational {
private:
	int numerator;
	int denominator;

	// Compute the greatet common divisor (GCD) of two integers
	static int gcd(int m, int n) {
		if (n == 0)
			return m;
		else
			return gcd(n, m % n);
	}
	// Compute the least common multiple (LCM) of two integers
	static int lcm(int m, int n) {
		return (m * n) / gcd(m, n);
	}

public:
	Rational() :numerator(0), denominator(1) {}

	Rational(int n, int d): numerator(n),denominator(d) {
		if (d == 0) {
			std::cout << "*****Warning---Illegal Rational\n";
			numerator = 0;		// Make up a reasonable defualt fraction
			denominator = 1;
		}
	}

	int get_numerator() const {
		return numerator;
	}

	int get_denominator() const {
		return denominator;
	}

	Rational reduce() const {
		int factor = gcd(numerator, denominator);
		return { numerator / factor, denominator / factor };
	}

	bool operator==(const Rational& fract) const {
		Rational f1 = reduce();
		Rational f2 = fract.reduce();
		return (f1.get_numerator() == f2.get_numerator()) && (f1.get_denominator() == f2.get_denominator());
	}

	bool operator!=(const Rational& fract) {
		return !(*this == fract);
	}

	Rational operator+(const Rational& fract) const {
		int commonDenominator = lcm(denominator, fract.denominator);
		int newNumerator = numerator * (commonDenominator / denominator) +
			fract.numerator * (commonDenominator / fract.denominator);
		return { newNumerator, commonDenominator };
	}

	Rational operator*(const Rational& fract) {
		return Rational(numerator * fract.numerator,
			denominator * fract.denominator).reduce();
	}
};



std::ostream& operator<<(std::ostream& os, const Rational& r) {
	os << r.get_numerator() << '/' << r.get_denominator();
	return os;
}

int main() {
	Rational f1(1, 2), f2(1, 3);

	std::cout << f1 << " + " << f2 << " = " << (f1 + f2) << '\n';
	std::cout << f1 << " * " << f2 << " = " << (f1 * f2) << '\n';

	return 0;
}