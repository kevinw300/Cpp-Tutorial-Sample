#include "stdafx.h"

#include <iostream>

class NoVTable {
private:
	int data;
public:
	void set(int d){
		data = d;
	}

	int get() {
		return data;
	}
};

class HasVTable {
private:
	int data;
public:
	virtual void set(int d) {
		data = d;
	}

	virtual int get() {
		return data;
	}
};

int main() {
	NoVTable no_vtable;
	HasVTable has_vtable;
	no_vtable.set(10);
	has_vtable.set(10);
	std::cout << "no_vtable size  = " << sizeof no_vtable << '\n';
	std::cout << "has_vtable size = " << sizeof has_vtable << '\n';
	return 0;
}