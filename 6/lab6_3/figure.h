#pragma once

class Figure {
	virtual double area() = 0;
	virtual void show() = 0;
};

class Circle : public Figure {
	int radius;
public:

	int* GetRadiusAdress();
	Circle(int _R);
	double area();
	void show();

};

class Rectangle : public Figure {
	int a;
	int b;
public:

	Rectangle(int _a, int _b);
	Rectangle(int _a);
	int* GetAAdress();
	int* GetBAdress();
	double area();
	void show();
};
