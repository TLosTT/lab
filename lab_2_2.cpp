#include <iostream>
#include <time.h>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;


class Abonent{
public:
	int id;
protected:
	string sName;
	string pNumber;
public:
	Abonent(int _id, string _sName, string _pNumber) {
	    cout << "\nConstructor" << endl;
		id = _id;
		sName = _sName;
		pNumber = _pNumber;
	}
	~Abonent() {
	cout << "\nDestrucktor" << endl;
	};


	friend class Notebook;
};

class Notebook {

public:

	void change(Abonent& ob, string _newPNumber) {
		ob.pNumber = _newPNumber;
	}
	void show(Abonent& ob) {
		cout << ob.id << '|';
		cout << ob.sName << '|';
		cout << ob.pNumber << endl;
		cout << '\n';
	}
};

int main() {
	vector<Abonent> abonentArr;
	Notebook notebook;
	abonentArr.push_back(Abonent(1, "Maxim", "893253564312"));
	abonentArr.push_back(Abonent(2, "Anatoliy", "892754885944"));
	abonentArr.push_back(Abonent(3, "Spencer", "892657978654"));
	abonentArr.push_back(Abonent(4, "Axiom", "8927657463523"));
	abonentArr.push_back(Abonent(5, "Verginiy", "891884857456"));
	for (int i = 0; i < abonentArr.size(); i++) {
		notebook.show(abonentArr[i]);
	}
	int nom;
	string nom2;
	cout<<"Vvedite id abonenta nujdaushegosya v izmenenii:";
	cin>>nom;
	cout<<"Na kakoi nomer?";
	cin>>nom2;
	for (int i = 0; i < abonentArr.size(); i++) {
		if (abonentArr[i].id == nom) {
			notebook.change(abonentArr[i], nom2);
			break;
		}
	}
	cout << "===========================================" << endl;
	for (int i = 0; i < abonentArr.size(); i++) {
		notebook.show(abonentArr[i]);
	}
	return 0;
}
