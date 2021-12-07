#include <locale>;
#include "figure.h"
#include "new_fig.h"
#include <iostream>
#include <locale>;
int main() {
	setlocale(LC_ALL, ("Russian"));
	Circle ob1(2);
	Rectangle ob2(4);
	Rectangle ob3(4,2);
	Triangle ob4(3.0, 4.0, 5.0);

	ob1.show();
	ob2.show();
	ob3.show();
	ob4.show();

	return 0;
}
