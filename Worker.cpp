#include <iostream>
#include <vector>

using namespace std;
///Создание класса
class Worker
{
    string surname;
    string position;
    int year;
    int salary;

    public:

    Worker(){
    cout<< "Surname: \n";
    cin>>surname;
    cout<< "Position: \n";
    cin>>position;
    cout<< "Year of joining: \n";
    cin>>year;
    cout<< "Salary: \n";
    cin>>salary;
    };
    ~Worker(){};
///Методы:
    void show(){
    cout<<"Name:"<<surname<<endl;
    cout<<"Position:"<<position<<endl;
    cout<<"Year of joining:"<<year<<endl;
    cout<<"Salary:"<<salary<<endl;
    };
    int getSalary(){
    return salary;
    };
    int getYear(){
    return year;
    };
    string getPosition(){
    return position;
    };
    void setSalary(int newSalary){
    salary = newSalary;
    };
};


int main() {
    vector<Worker> array;
    int kol;
    string kol2;
    cout<<"Vvedite kolichestvo sotrudnikov:"; ///Количество сотрудников
    cin>>kol;
    for (int i = 0; i < kol; i++){
    array.push_back(Worker());      ///Создание каждого из сторудников с помещением их в массив
    }
    int size = array.size();
    cout<<"Vvedite velichinu staja v godah:";       ///Первая выборка по условию
    cin>>kol;
    cout<<"Sotrudniki so stagem >"<<kol<<" let:"<<endl;
    for (int i = 0; i < size; i++){
        if ((2021 - array[i].getYear()) > kol){
            array[i].show();
            cout<<""<<endl;
        }
    }
    cout<<"Vvedite zarplatu bolshe cotoroi neobhodimo nayti:";      ///Вторая выборка по условию
    cin>>kol;
    cout<<"Sotrudniki s zarplatoi bolee "<<kol<<endl;
    for (int i = 0; i < size; i++){
        if (array[i].getSalary() > kol){
            array[i].show();
            cout<<""<<endl;
        }
    }
    cout<<"Vvedite nujnuu rabotu:";     ///Третья выборка по условию
    cin>>kol2;
    cout<<"Sotrudniki s rabotoi "<<kol2<<endl;
    for (int i = 0; i < size; i++){
        if (array[i].getPosition() == kol2){
            array[i].show();
            cout<<""<<endl;
        }
    }


    return 0;
};



