#include <iostream>
#include <math.h>

using namespace std;
double point(double x1, double y1, double x2, double y2);                       ///sozdanie funkziy
double point(double x1, double y1, double z1, double x2, double y2, double z2);

double point(double x1, double y1, double x2, double y2) {                      ///opisivaniye funkziy
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}
double point(double x1, double y1, double z1, double x2, double y2, double z2) {
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2) + pow((z2 - z1), 2));
}

int main() {
	cout << "2d prostranstvo " << endl;                                         ///ispolzovaniye funkzii s kolichestvom parametrov dlya 2d pranstranstva(2: x and y)
        double a = point(-4.0,0.0,0.0, 4.0);
        double b = point(0.0,4.0,4.0, 0.0);
        double c = point(-4.0,0.0,4.0, 0.0);
        double P = a + b + c;
	cout << "Perimetr " << P << endl << endl;
	cout << "3d prostranstvo " << endl;                                         ///ispolzovaniye funkzii s kolichestvom parametrov dlya 3d pranstranstva(2: x, y, z)
        a = point(-4.0, 5.0, 2.0, 0.0, 2.0,3.0);
        b = point(0.0, 2.0, 3.0, -6.0, 2.0, 4.0);
        c = point(-6.0, 2.0, 4.0, -4.0, 5.0, 2.0);
        P = a + b + c;
	cout << "Perimetr " << P << endl << endl;
	return 0;
}
