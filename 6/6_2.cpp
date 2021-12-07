#include <iostream>
#include <string>
#include <locale>
using namespace std;

class DomesticAnimal {
protected:
    int weight;
	int price;
	string color;
public:
	DomesticAnimal() {
		price = 0;
		weight = 0;
		color = "brown";
		cout << "����������� Default DomesticAnimal"<<endl;
	}
	DomesticAnimal(int price_o, int weight_o, string color_o) {
		price = price_o;
		weight = weight_o;
		color = color_o;
		cout << "����������� Parameters DomesticAnimal"<<endl;
	}
	void Print(){
		cout << price << "  " << weight << "  " << color << "  ";
		cout << "����������� DomesticAnimal ";
	}
};

class Cow: virtual public DomesticAnimal {
public:
    Cow() {cout << "����������� Default Cow" << endl;}

	Cow(int price_o, int weight_o, string color_o) : DomesticAnimal(price_o, weight_o, color_o) {
        cout << "����������� Parameters Cow" << endl;
	}

	void Print() {
		cout << price << "  " << weight << "  " << color << "  ";
		cout << "����������� Cow ";
	}
};

class Buffalo : virtual public DomesticAnimal {
public:
    Buffalo() {cout << "����������� Default Buffalo" << endl;}


	Buffalo(int price_o, int weight_o, string color_o) : DomesticAnimal(price_o, weight_o, color_o) {
        cout << "����������� Parameters Buffalo" << endl;
	}

	void Print() {
		cout << price << "  " << weight << "  " << color << "  ";
		cout << "����������� Buffalo ";
	}
};

class Beefalo : public Cow,  public Buffalo{
public:
	Beefalo(int price_o, int weight_o, string color_o)
	    {price = price_o;
	    weight = weight_o;
	    color = color_o;
	    cout << "����������� Beefalo" <<endl;}
	void Print() {
		cout << DomesticAnimal::price << "  " << DomesticAnimal::weight << "  " << DomesticAnimal::color << endl;
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	Beefalo b(2, 2, "blue");
	b.Print();
	return 0;
}
