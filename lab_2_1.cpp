#include <iostream>
using namespace std;

class Test {
protected:
	int W;
	void Z(){
		cout << "Eto zakritaya funciya Test" << endl;
	}
public:
	Test() {
		W = 1;
	}
	~Test() {};

	friend void fun(Test _ob);
};

void fun(Test _ob) {
	cout << _ob.W << endl;
	_ob.Z();
}

int main() {
	Test ob;
	fun(ob);

    return 0;
}
