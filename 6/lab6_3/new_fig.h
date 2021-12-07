#pragma once
#include "figure.h"

class Triangle : public Figure {
	double a;
	double b;
	double c;
public:

	Triangle(double _a, double _b, double _c);
	double area();
	void show();

};
