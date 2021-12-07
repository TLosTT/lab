#include <iostream>;
#include <string>;
#include <locale>;
using namespace std;

class Base1 {
private:
	int i;
public:
	Base1() {
		i = 0;
		cout << "Конструктор Base1 без параметров \n";
	}
	Base1(int i_o) {
		i = i_o;
		cout << "Конструктор Base1 c параметром \n";
	}
	void Put(int val) {
		i = val;
	}
	int Get() {
		return i;
	}
};

class Base2 {
private:
	string name;
public:
	Base2() {
		name = "Пусто";
		cout << "Конструктор Base2 без параметров \n";
	}
	Base2(string name_o) {
		name = name_o;
		cout << "Конструктор Base2 с параметром \n";
	}
	void Put(string value) {
		name = value;
	}
	string Get() {
		return name;
	}
};

class Derived :  public Base2, public Base1 {
private:
	char ch;
public:
	Derived() {
		ch = 'V';
		cout << "Конструктор Derived без параметров \n";
	}
	Derived(char ch_o, string name_o, int i_o): Base2(name_o), Base1(i_o){
		ch = ch_o;
		cout << "Конструктор Derived с параметрами \n";
	}
	void Put(char value) {
		ch = value;
	}

	char Get() {
	    return ch;
	}
	friend ostream& operator<<(ostream& out, Derived& ob);
};

ostream& operator<<(ostream& out, Derived& ob) {
    return out << ob.Get() << "\n" << ob.Base1::Get() << "\n" << ob.Base2::Get() << "\n";
}

int main() {
	setlocale(LC_ALL, "Russian");
	Derived ob, ob2('A',"bubble",3);
	cout << ob << ob2;

	return 0;
}
