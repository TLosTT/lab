#include "new_fig.h"
#include <cmath>
#include <iostream>
#include <locale>;
using namespace std;

Triangle::Triangle(double _a, double _b, double _c) {
	if (_a < 0 and _b < 0 and _c < 0 and _a + _b > _c and _a + _c > _b and _b + _c > _a) {

	}
	a = _a;
	b = _b;
	c = _c;
}

double Triangle::area() {
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

void Triangle::show() {
	cout << "Triangle:" << endl;
	cout << "A = " << a << endl;
	cout << "B = " << b << endl;
	cout << "C = " << c << endl;
	cout << "Area = " << area() << endl;
	cout << "\n";
}
