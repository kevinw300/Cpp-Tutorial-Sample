#include "stdafx.h"
#include "linkedlist.h"

#include <iostream>


int main() {
	bool done = false;
	char command;
	int value;
	LinkedList<int> list;

	while (!done) {

		std::cout << "I)nsert <item> D)elete P)rint L)ength E)rase Q)uit: ";

		std::cin >> command;
		command = tolower(command);

		switch (command) {

		case 'i':		// insert
			if (std::cin >> value)
				list.insert(value);
			else
				done = true;
			break;
		case 'd':		// delete
			if (std::cin >> value)
				if (list.remove(value))
					std::cout << value << " removed.\n";
				else
					std::cout << value << " not found.\n";
			else
				done = true;
			break;
		case 'p':
			list.print();
			break;
		case 'l':
			std::cout << "Number of elements: " << list.length() << '\n';
			break;
		case 'e':
			list.clear();
			break;
		case 'q':
			done = true;
			break;
		}
	}

	list.clear();		// Free up the space held by the linked list

	return 0;
}
