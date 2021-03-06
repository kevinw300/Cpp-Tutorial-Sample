#include "stdafx.h"

#include <iostream>

int evaluate(int(*f)(int, int), int x, int y) {
	return f(x, y);
}

int main() {
	int val = evaluate([](int x, int y)->int {return x * y; }, 2, 3);
	int val2 = evaluate([](int x, int y) {return 3 * x + y; }, 10, 2);

	auto f = [](int x) {return 5 * x; };

	std::cout << val << '\t' << val2 << '\t' << f(10) '\n';
	return 0;
}
