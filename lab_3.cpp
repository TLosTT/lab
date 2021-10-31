#include <iostream>
#include <string>
using namespace std;

class Goods {
	string name;
	string date;
	int cost;
	int num;
	int id;
public:
	Goods(string _name, string _date, int _cost, int _num, int _id) {
	    cout << "Vizvan constructor s parametrami" << endl;
		name = _name;
		date = _date;
		cost = _cost;
		num = _num;
		id = _id;
	}
	Goods() {
	    cout << "Vizvan constructor po umolchaniu" << endl;
		name = "Unkown";
		date = "0000-00-00";
		cost = 0;
		num = 0;
		id = 0;
	}
	Goods(Goods& _ob) {
	    cout << "Vizvan constructor copirovaniya" << endl;
		name = _ob.name;
		date = _ob.date;
		cost = _ob.cost;
		num = _ob.num;
		id = _ob.id;
	}
	~Goods() {
		cout << "Vizvan destructor"<< endl;
	};

public:
	void Show() {
		cout<< endl << "Nazvanie tovara: " << name << endl;
		cout << "Data oformleniya tovara: " << date << endl;
		cout << "Cena tovara: " << cost << endl;
		cout << "Colichestvo tovara: " << num << endl;
		cout << "Nomer nakladnoi " << id << endl<<endl;
	}

	Goods operator=(Goods& _ob);

};

Goods tovar(Goods& _s) {
	return _s;
}

Goods Goods::operator=(Goods& _ob) { ///Peregruzca operatora prisvaivaniya
	name = _ob.name;
	date = _ob.date;
	cost = _ob.cost;
	num = _ob.num;
	id = _ob.id;
	cout << "Operator" << endl;
	return *this; ///Vozvrat levogo operanda s novimi znacheniyami
}


int main() {
	Goods nakl1("RMX2086", "20.10.2021", 30000, 500, 1); ///sozdaniye pervogo objecta
	Goods nakl2(nakl1);         ///sozdaniye vtorogo objecta putem copirovaniya
	Goods nakl3;        ///sozdaniye tretego objecta
	tovar(nakl2);
	nakl1 = nakl3;      ///prisvaivaniye cherez peregrujenniy operator
	nakl1.Show();
	nakl2.Show();
	return 0;
}
