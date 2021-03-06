#include <iostream>

/*
* The Point class defines the structure of software
* objects that model mathematical, geometric points
*/
class Point {
private:
	double x;	// The point's x corrdinate
	double y;	// The pints's y coordinate
public:
	Point(double x, double y):x(x), y(y) {}

	double get_x() const {
		return x;
	}
	double get_y() const {
		return y;
	}

};

std::ostream& operator<<(std::ostream& os, const Point& pt) {
	os << '(' << pt.get_x() << ',' << pt.get_y() << ')';
	return os;
}

Point operator+(const Point& pt1, const Point& pt2) {
	return {
		pt1.get_x() + pt2.get_x(),
		pt1.get_y() + pt2.get_y()
	};
}

int main() {
	// Declare point object
	Point pt1(8.5, 9.2);
	Point pt2(2.4, 4.5);

	std::cout << pt1 << '\n';
	std::cout << pt1 + pt2 << '\n';
	return 0;
}