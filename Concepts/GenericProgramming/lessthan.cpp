#include "stdafx.h"
#include <iostream>

/*
template <typename T>
bool less_than(T a, T b) {
	return a < b;
}
*/

// For efficiency purpose, the better way to write less_than is:
template <typename T>
bool less_than(const T& a, const T& b) {
	return a < b;
}
int main() {
	std::cout << less_than(2, 3) << '\n';
	std::cout << less_than(2.2, 2.7) << '\n';
	std::cout << less_than(2.7, 2.2) << '\n';

	std::string word1 = "ABC", word2 = "XYZ";
	std::cout << less_than(word1, word2) << '\n';
	std::cout << less_than(word2, word1) << '\n';
	return 0;
}