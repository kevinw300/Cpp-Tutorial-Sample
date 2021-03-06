#include <iostream>

/*
 * The Point class defines the structure of software
 * objects that model mathematical, geometric points
 */
class Point {
public:
	double x;	// The point's x corrdinate
	double y;	// The pints's y coordinate
};

int main() {
	// Declare some point object
	Point pt1, pt2;
	// Assign their x and y field
	pt1.x = 8.5;
	pt1.y = 0.0;
	pt2.x = -4;
	pt2.y = 2.5;

	std::cout << "pt1 = (" << pt1.x << ", " << pt1.y << ")\n";
	std::cout << "pt2 = (" << pt2.x << ", " << pt2.y << ")\n";
	pt1 = pt2;
	std::cout << "pt1 = (" << pt1.x << ", " << pt1.y << ")\n";
	std::cout << "pt2 = (" << pt2.x << ", " << pt2.y << ")\n";
	return 0;
}