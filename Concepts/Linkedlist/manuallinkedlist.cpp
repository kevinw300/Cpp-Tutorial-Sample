#include "stdafx.h"

#include <iostream>

using namespace std;
/*
 * Use struct instead of class since we will consider Node
 * object a primitive data type that requires no speical 
 * protection from clients
 **/

struct Node {
	int data;
	Node *next;
	
	Node(int d, Node *n): data (d), next(n) {}
};

int main() {
	Node n4(3, nullptr);
	Node n3(10, &n4);
	Node n2(23, &n3);
	Node n1(34, &n2);

	for (Node *cursor = &n1; cursor != nullptr; cursor = cursor->next) {
		std::cout << cursor->data << " ";
	}
	std::cout << '\n';
	return 0;
}