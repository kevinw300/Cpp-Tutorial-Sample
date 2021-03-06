#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>

/*
* binary_search(a, seek)
*		Returns the index of element seek in vector a;
*		returns -1 if seek is not an element of a
*		a is the vector to search; a's contents must be
*		in ascending order
*		seek is the element to find
*/
int binary_search(const std::vector<int>& a, int seek) {
	int n = a.size();

	int first = 0;			// Initially the first element in vector
	int last = n - 1;		// Initially the last element in vector
	int mid;				// The middle of the vector

	while (first <= last) {
		mid = first + (last - first + 1) / 2;
		if (a[mid] == seek)
			return mid;			// Found it
		else if (a[mid] > seek)
			last = mid - 1;		// continue with 1st half
		else
			first = mid + 1;	// continue with 2nd half
	}
	return -1;	// Element not found
}
/*
*  linear_search(a, seek)
*		Returns the index of element seek in vector a.
*		Returns -1 if seek is not an element of a.
*		a is the vector to search
*		seek is the element to find
*		This version requires vector to be sorted in
*		ascending order.
*/
int linear_search(const std::vector<int>& a, int seek) {
	int n = a.size();

	for (int i = 0; i < n && a[i] <= seek; i++)
		if (a[i] == seek)
			return i;	// Return position immediatelly

	return -1;			// Element not found
}

/*
*	Tests the execution speed of a given search function on a vector.
*	search	- the search function to test
*	v		- the vector to search
*	trivial	- the number of trial runs to average
*	Ruturns the elapsed time in seconds
*	The C++ chrono library defines the types.
*	system_clock::time_point and microseconds.
*/
double time_execution(int(*search)(const std::vector<int>&a, int),
	std::vector<int>& v, int trials) {

	int n = v.size();

	double elapsed = 0.0;
	for (int iters = 0; iters < trials; iters++) {
		clock_t start_time = clock();		// Start the timer
		for (int i = 0; i < n; i++)			// Search for all element
			search(v, i);
		clock_t end_time = clock();			// Stop the timer

		elapsed = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
	}
	return elapsed / trials;				// Mean elapsed time per run
}

int main() {
	std::cout << "----------------------------------------------------------------\n";
	std::cout << "        Vector                   Linear                   Binary\n";
	std::cout << "        Size                     Search                   Search\n";
	std::cout << "----------------------------------------------------------------\n";

	for (int size = 0; size <= 50000; size += 5000) {
		std::vector<int> list(size);

		for (int i = 0; i < size; i++)
			list[i] = i;


		std::cout << std::setw(13) << size;

		std::cout << std::fixed << std::setprecision(3) << std::setw(25)
			<< time_execution(linear_search, list, 5) << " sec";

		std::cout << std::fixed << std::setprecision(3) << std::setw(25)
			<< time_execution(binary_search, list, 5) << " sec\n";
	}
	return 0;
}

