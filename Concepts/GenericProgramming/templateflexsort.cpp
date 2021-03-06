#include "stdafx.h"

#include <iostream>
#include <vector>
#include <utility>	// For generic swap function

// For efficiency purpose, the better way to write less_than
// is to use passed by reference.. which does not need to make
// copies of a and b
template <typename T>
bool less_than(const T& a, const T& b) {
	return a < b;
// less_than (2, 2.2)  <- error
// we can use: less_than<int>(2,2.2) or less_than<double>(2,2.2)
}

template <typename T>
bool greater_than(const T& a, const T& b) {
	return a > b;
}

template <typename T, typename V>
bool less_than(const T& a, const V& b) {
	return a < b;
}
/*
 *	selection_sort(a, n, compare)
 *	Arranges the elemnets of vector vec in an order determined by the compare function
 * vec is a vector
 * compare is a function that compares the ordering of two types that
 *		support the < operator.
 * The contents of vec are physically rearranged.
 */
template <typename T>
void selection_sort(std::vector<T>& vec, 
	bool (*compare)(const T&, const T&)) {
	
	int n = vec.size();
	for (int i = 0; i < n - 1;i++) {
		// Note: i, small, and j represent positions within vec.
		// vec[i], vec[small] and a[j] represents the elements at
		// those positions.
		// small is the position of the smallest value we've seen
		// so far; we use it to find the smallest value less
		// than vec[i]
		int small = i;
		// see if a smaller value can be found later in the vector
		for (int j = i + 1; j < n; j++) 
			if (compare(vec[j], vec[small]))
				small = j;		// found a smaller value
		// swap vec[i] and vec[small], if a smaller value was found
		if (i != small)
			std::swap(vec[i], vec[small]);		// uses swap from <utility>
	}
}

/*
 *	print
 *		Prints the contents of a vector
 *		vec is the vector to print
 *		The function does not modify vec.
 */
template <typename T>
void print(const std::vector<T>& vec) {
	int n = vec.size();
	std::cout << '{';
	if (n > 0) {
		std::cout << vec[0];	// Print the first element
		for (int i = 1; i < n; i++)
			std::cout << ',' << vec[i];
	}
	std::cout << '}';
}

template <typename T>
T sum(const std::vector<T>& v) {
	T result = 0;
	for (T elem : v)
		result += elem;
	return result;
}

int main() {
	std::cout << less_than(2, 3) << '\n';
	std::cout << less_than(2.2, 2.7) << '\n';
	std::cout << less_than(2.7, 2.2) << '\n';

	std::string word1 = "ABC", word2 = "XYZ";
	std::cout << less_than(word1, word2) << '\n';
	std::cout << less_than(word2, word1) << '\n';
	
	std::cout << less_than(2, 2.2) << '\n';

	std::vector<double> v{ 10,20,30 };
	std::vector<int> w{ 10, 20, 30 };

	std::cout << sum(v) << '\n';
	std::cout << sum(w) << '\n';

	std::vector<int> list{ 23,-3,4,215,0,-3,2,23,100,88,-10 };
	std::cout << "Original: ";
	print(list);
	std::cout << '\n';
	selection_sort(list, less_than<int>);
	std::cout << "Ascending: ";
	print(list);
	std::cout << '\n';

	return 0;
}