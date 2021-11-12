#include <iostream>

using namespace std;

class Date {
protected:
	int day, month, year;
	int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
public:
	Date() {
		day = 0;
		month = 0;
		year = 0;
	}
	Date(int _day, int _month, int _year) {
		day = _day;
		month = _month;
		year = _year;
	}
	~Date() {};
	friend ostream& operator<<(ostream& out,Date& ob);
	Date operator+(Date& ob);
	Date operator-(Date& ob);
	Date operator++(int _day);
	Date operator--(int _day);
	Date operator+(int day);
	Date operator-(int day);
};

ostream& operator<<(ostream& out, Date& ob){    ///peregruzka << dlya vstavki dati v potok vivoda

	return out << ob.day << "." << ob.month<<"."<< ob.year;
}

Date Date::operator+(Date& ob) {    ///peregruzka operatora + dlya sroka sdachi
	Date temp;
	temp.month = month + ob.month;
	temp.day = day + ob.day;
    temp.year += year + ob.year;
		if (temp.month == 1 or temp.month == 3 or temp.month == 5 or temp.month == 8 or temp.month == 7 or temp.month == 10 or temp.month == 12) {
			if (temp.day > 31) {temp.day -= 31; temp.month++;}
		}
		else if (temp.month == 2) {
			if (temp.day > 28) {temp.day -= 28; temp.month++;}
		}
		else {
			if (temp.day > 30) {temp.day -= 30; temp.month++;}
		}
	while (temp.month > 12) {temp.month -= 12; temp.year++;}
	return temp;
}

Date Date::operator-(Date& ob) {    ///peregruzka operatora + dlya sroka sdachi
	Date temp;
	temp.month = month - ob.month;
	temp.day = day - ob.day;
    temp.year = year - ob.year;
	while (temp.day > 31 or temp.day < 1) {
		if (temp.month == 1 or temp.month == 2 or temp.month == 4 or temp.month == 6 or temp.month == 8 or temp.month == 9 or temp.month == 11) {
			if (temp.day < 1) {temp.day += 31; temp.month--;}
		}
		else if (temp.month == 3) {
			if (temp.day > 28) {temp.day += 28; temp.month--;}
		}
		else {
			if (temp.day < 1) {temp.day += 30; temp.month--;}
		}
	}
	while (temp.month < 1) {temp.year--; temp.month += 12;}
	return temp;
}

Date Date::operator+(int _day) {            ///peregruzka operatora + dlya dati postavki
	Date temp;
	temp.day = day + _day;
	temp.month = month;
	temp.year = year;
		if (temp.month == 1 or temp.month == 3 or temp.month == 5 or temp.month == 7 or temp.month == 8 or temp.month == 10 or temp.month == 12) {
			if (temp.day > 31) {temp.day -= 31; temp.month++;}
		}
		else if (temp.month == 2) {
			if (temp.day > 28) {temp.day -= 28; temp.month++;}
		}
		else {
			if (temp.day > 30) {temp.day -= 30; temp.month++;}
		}
	while (temp.month > 12) {temp.month -= 12; temp.year++;}
	return temp;
}

Date Date::operator-(int _day) {            ///peregruzka operatora - dlya zarapotnoi plati
	Date temp;
	temp.day = day - _day;
	temp.month = month;
	temp.year = year;

		if (temp.month == 1 or temp.month == 2 or temp.month == 4 or temp.month == 6 or temp.month == 8 or temp.month == 9 or temp.month == 11) {
			if (temp.day < 1) {temp.day += 31; temp.month--;}
		}
		else if (temp.month == 3) {
			if (temp.day < 1) {temp.day += 28; temp.month--;}
		}
		else {
			if (temp.day < 1) {temp.day += 30; temp.month--;}
		}
	while (temp.month < 1) {temp.year--; temp.month += 12;}
	return temp;
}

Date Date::operator++(int _day) {           ///peregruzka dlya otchetnih dokumentov
	Date temp;
	temp.day = day+1;
	temp.month = month;
	temp.year = year;
		if (temp.month == 1 or temp.month == 3 or temp.month == 5 or temp.month == 7 or temp.month == 8 or temp.month == 10 or temp.month == 12) {
			if (temp.day > 31) {temp.day = 1; temp.month++;}
		}
		else if (temp.month == 2) {
			if (temp.day > 28) {temp.day = 1; temp.month++;}
		}
		else {
			if (temp.day > 30) {temp.day = 1; temp.month++;}
		}
	while (temp.month > 12) {temp.month - 12; temp.year++;}
	return temp;
}
Date Date::operator--(int _day) {           ///peregruzka dlya otchetnih dokumentov
	Date temp;
	temp.day = day-1;
	temp.month = month;
	temp.year = year;

		if (temp.month == 1 or temp.month == 2 or temp.month == 4 or temp.month == 6 or temp.month == 8 or temp.month == 9 or temp.month == 11) {
			if (temp.day < 1) {temp.day += 31;temp.month--;}
		}
		else if (temp.month == 3) {
			if (temp.day < 1) {temp.day += 28; temp.month--;}
		}
		else {
			if (temp.day < 1) {temp.day += 30; temp.month;}
		}

	while (temp.month < 1) {temp.year--; temp.month + 12;}
	return temp;
}

int main() {
	Date start(1, 1, 2000), constructing(29, 0, 0);                                ///sozdaniye objectov
	Date rezult = start + constructing;
	cout << "Data nachala stroitelstva: " << start << endl;
	cout << "Vremya stroitelstva: " << constructing << endl;
    cout<<"______________________________________________________"<<endl;
	cout << "Data sdachi objectov (date+date): " << rezult << endl;
    cout<<"______________________________________________________"<<endl;
	rezult = start - constructing;
	cout << "Data nachala stroitelstva (Date-Date): " << rezult << endl;
    cout<<"______________________________________________________"<<endl;
	rezult = start + 31;
	cout << "Data postavki stroi materialov (Date+Int): " << rezult << endl;
    cout<<"______________________________________________________"<<endl;
	rezult = start - 31;
	cout << "Data dlya vichesleniya zarpalti (Date-Int): " << rezult << endl;
    cout<<"______________________________________________________"<<endl;
	rezult = rezult++;
	cout << "Perehod k sleduyushey date (date++): " << rezult << endl;
    cout<<"______________________________________________________"<<endl;
	rezult = rezult--;
	cout << "Perehod k preditushey date (Date--): " << rezult << endl;
	return 0;
}
