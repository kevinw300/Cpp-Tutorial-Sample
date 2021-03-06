#include <iostream>
#include <vector>
/*
 * print
 *		Prints the contents of a vector of intergers
 *		a is the vector to print; a is const
 */
void print(const std::vector<int>& a) {

	int arr_size = a.size();

	std::cout << '{';
	for (int i = 0; i < arr_size - 1; i++)
		std::cout << a.at(i) << ", ";
	std::cout << a.at(arr_size - 1) << "}\n";

}

/*
 * permute
 *		Prints all the permutations of vector a in the
 *		index range begin...end, inclusive, The function's
 *		behavior is undefined if begin or end represents
 *		is outside the bounds of vector a.
 */
void permute(std::vector<int>& a, int begin, int end) {
	if (begin == end) {
		print(a);
	}
	else {
		for (int i = begin; i <= end; i++) {
			// Intercharge the element at the first position
			// with the element at position i
			std::swap(a[begin], a[i]);
			// Recursively permute the rest of the vector
			permute(a, begin + 1, end);
			// Interchange the current element at the first position
			// with the current element at position i
			std::swap(a[begin], a[i]);
		}
	}
}

int main() {
	std::vector<int> a{ 0, 1, 2, 3, 4 };

	std::cout << "Original list is: ";
	print(a);

	std::cout << "Permutations: \n";
	permute(a, 0, 4);
	return 0;
}

