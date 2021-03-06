#include <iostream>


void iterative_print(const int *a, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << ' ';
	}
}

void recursion_print(const int *a, int n) {
	if (n > 0) {
		std::cout << *a << ' ';
		recursion_print(a + 1, n - 1);
	}
	std::cout << '\n';
}

int main() {

	int arr[] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
	int *begin, *end, *cursor;

	begin = arr;		// begin points to the first element of arr 
	end = arr + 10;		// end points to the last element of arr 
	// Prints out the contents of arr
	cursor = begin;
	while (cursor != end) {
		std::cout << *cursor << " ";	// Print the element
		cursor++;	// Increment cursor so it points to next element
	}

	std::cout << '\n';

	recursion_print(arr, 10);

	return 0;
}

