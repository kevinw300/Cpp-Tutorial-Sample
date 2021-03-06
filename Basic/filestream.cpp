#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/*
 * save_vector(filename, v)
 *		Writes the contents of vector v.
 *		filename is name of text file created. Any file
 *		by that anem is overwritten.
 *		v is a vector holding integers. v is unchanged by
 *		the function.
 */

void save_vector(const std::string& filename, const std::vector<int>& vec) {
	// open a text for writting
	std::ofstream out(filename);
	if (out.good()) {		// Make sure the file was opened properly
		int n = vec.size();
		for (int i = 0; i < n; i++) {
			out << vec[i] << ' ';
		}
		out << '\n';
	}
	else
		std::cout << "Unable to save the file.\n";
}

/*
 * load_vector(filename, v)
 *		Reads the contents of vector v from text file
 *		filename. v's contents are replaced by the file's
 *		contents. If the file cannot be found, the vector v
 *		is empty
 *		v is a vector holding integers.
 */
void load_vector(const std::string& filename, std::vector<int>& vec) {
	// open a text for reading
	std::ifstream in(filename);
	if (in.good()) {		// Make sure the file was opened proerly
		vec.clear();		// Start with empty vector
		int value;
		while (in >> value)
			vec.push_back(value);	// Read until end of file
	}
	else
		std::cout << "Unable to load in the file\n";
}

/*
 * print_vector (v)
 *		Prints the contents of vector v.
 *		v is a vector holding integers.
 */
void print_vector(const std::vector<int>& vec) {
	int len = vec.size();
	std::cout << '{';

	if (len > 0) {
		for (int i = 0; i < len - 1; i++) {
			std::cout << vec[i] << ", ";
		}
		std::cout << vec[len - 1];
	}
	std::cout << "}\n";
}


int main() {
	std::vector<int> list;
	bool done = false;
	char command;

	while (!done) {

		std::cout << "I)nsert <item> P)rint S)ave <filename) L)oad <filename> E)rase Q)uit: ";

		std::cin >> command;
		command = tolower(command);

		int value;
		std::string filename;

		switch (command) {

		case 'i':
			std::cin >> value;
			list.push_back(value);
			break;
		case 'p':
			print_vector(list);
			break;
		case 's':
			std::cin >> filename;
			save_vector(filename,list);
			break;
		case 'l':
			std::cin >> filename;
			load_vector(filename, list);
			break;
		case 'e':
			list.clear();
			break;
		case 'q':
			done = true;
			break;
		}
	}
	return 0;
}

