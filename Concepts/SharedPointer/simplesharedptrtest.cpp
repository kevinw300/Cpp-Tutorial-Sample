#include "stdafx.h"

#include <iostream>
#include <string>
#include <memory>

struct Widget {
	static unsigned id_source;	// Source of unique IDs
	unsigned id;

	Widget() :id(id_source++) {
		std::cout << "Creating a widget #" << id << " ("
			<< reinterpret_cast<uintptr_t>(this)
			<< ")\n";
	}

	~Widget() {
		std::cout << "Destorying a widget #" << id << " ("
			<< reinterpret_cast<uintptr_t>(this)
			<< ")\n";
	}

};

unsigned Widget::id_source = 0;
// Gloabl shared pointer
auto global_ptr = std::make_shared<Widget>();
// auto = std::shared_ptr<Widget>

std::shared_ptr<Widget> make_widget() {
	std::cout << "---- Entering make_widget ----\n";
	std::cout << "---- Leaving make_widget ----\n";
	return std::make_shared<Widget>();
}

void test1() {
	std::cout << "---- Entering Test 1 ----\n";
	// Make p point to a dynamically created widget object
	auto p = std::make_shared<Widget>();
	std::cout << p->id << '\n';
	p->id = 25;
	std::cout << p->id << '\n';
	std::cout << "---- Leaving Test 1 ----\n";
}

void test2() {
	std::cout << "---- Entering Test 2 ----\n";
	// Make q point to a dynamically created widget object
	auto q = std::make_shared<Widget>();
	std::cout << q->id << '\n';
	q = nullptr;	// Make q point to nothing
	std::cout << "---- Leaving Test 1 ----\n";
}

void test3() {
	std::cout << "---- Entering Test 3 ----\n";
	// Make p point to a dynamically created integer
	auto p = std::make_shared<int>(55);
	std::cout << *p << '\n';
	*p = -4;
	std::cout << *p << '\n';
	std::cout << "---- Leaving Test 3 ----\n";
}

void test4() {
	std::cout << "---- Entering Test 4 ----\n";
	auto p = make_widget();
	std::cout << p->id << '\n';
	std::cout << "---- Leaving Test 4 ----\n";
}


void test5() {
	std::cout << "---- Entering Test 5 ----\n";
	auto p = make_widget();
	std::cout << p->id << '\n';
	std::cout << "---- Leaving Test 5 ----\n";
}


void test6() {
	std::cout << "---- Entering Test 6 ----\n";
	// Aliasing
	auto q = std::make_shared<Widget>();
	auto r = q;
	auto s = q;

	std::cout << q->id << ' '
		<< r->id << ' '
		<< s->id << '\n';

	q = nullptr;
	std::cout << r->id << ' '
		<< s->id << '\n';

	r = nullptr;
	std::cout << s->id << '\n';

	s = nullptr;
	std::cout << "---- Leaving Test 6 ----\n";
}


int main() {
	std::cout << "---- Entering main ----\n";
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	std::cout << "---- Leaving main ----\n";
	return 0;
}