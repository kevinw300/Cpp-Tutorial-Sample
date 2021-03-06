#include <iostream>
#include <limits>

int main() {
	int x;

	std::cout << "Please enter an integer: ";

	while (!(std::cin >> x)) {
		// Report error and re-prompt
		std::cout << "Bad entry, please try again: ";
		std::cin.clear();	// Clear the error state of the stream
		// Empty the keyboard buffer
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
	}

	std::cout << "You entered " << x << '\n';
	return 0;
}

