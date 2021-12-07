#include <iostream>
#include "figure.h"
#include <locale>;
using namespace std;

int* Circle::GetRadiusAdress() {
	return &radius;
}

Circle::Circle(int _R) {
	if (_R > 0) {
		radius = _R;
	}
	else {
		cout << "Ошибка";

	}
}

double Circle::area() {
	return 3.14 * radius * radius;
}


void Circle::show() {
	cout << "Circle" << endl;
	cout << "Radius: "<< radius << endl;
	cout << "Area: "<< Circle::area() << endl;
	cout << "\n";
}
Rectangle::Rectangle(int _a, int _b) {
	a = _a;
	b = _b;
}
Rectangle::Rectangle(int _a) {
	a = _a;
}

int* Rectangle::GetAAdress() {
	return &a;
}

int* Rectangle::GetBAdress() {
	return &b;
}
double Rectangle::area() {
	if (b <= 0) {
		return (a * a);
	}
	else {
		return (a * b);
	}
}

void Rectangle::show() {
    setlocale(LC_ALL, ("Russian"));
	if (b <= 0) {
		cout << "Square" << endl;
		cout << "Side: " << a << endl;
	}
	else {
		cout << "Rectange" << endl;
		cout << "Hight: " << a << endl;
		cout << "With: " << b << endl;
	}

	cout << "Area: " << area() << endl;
	cout << "\n";
}
