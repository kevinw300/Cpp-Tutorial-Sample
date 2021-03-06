#include "stdafx.h"
#include "intlist4.h"
#include <iostream>

using namespace std;

void f() {
	IntList4 list1, list2;		// Constructor called here
	list1.insert(10);
	list1.insert(-2);
	list1.insert(8);
	list1.print();

	list2.insert(2);
	list2.insert(5);
	list2.print();

	std::cout << "-------------\n";

	list1 = list2;		// Memory leak free
	list1.print();
}

int main() {
	f();

	std::cout << "All done.\n";

	return 0;
}