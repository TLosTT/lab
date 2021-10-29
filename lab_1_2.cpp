#include <iostream>
#include <iomanip>
#include <list>
#include <vector>
#include <string>
using namespace std;

class Stock{
    string company_name;
    int stock_num;
    vector<float> stock_cost_array;
    float stock_cost;
    double all_stock_cost;

    void SetTotal(){
    all_stock_cost = 0;
    for (int i = 0; i < stock_num; i++){
        all_stock_cost += stock_cost_array[i];
        }
    }

    public:
///Конструкторы:
    Stock(){
        cout << "Constructor bez parametrov sozdan \n" << endl;
        company_name = "Pervaya companiya";
        stock_num = 1;
        all_stock_cost = 10;
    }

     Stock(string s, int i){
        cout << "Constructor s parametrami sozdan" << endl;
        company_name = s;
        stock_num = i;
        cout << "Vvedite stoimost kajdoi akzii:" << endl;
        for (int i = 0; i < stock_num; i++) {
            int s_cost;
            cout << "Akziya nomer " << i+1 << " : ";
            cin >> s_cost;
            stock_cost_array.push_back(s_cost);
        }
        SetTotal();
     }

    void Show(){
        cout << "Nazvanie companii: " << setw(1) << company_name << endl;
        cout << "Obshee colischestvo akziy: " << setw(1) << stock_num << endl;
        cout << "Obshaya stoimost vseh akziy: " << setw(1) << all_stock_cost << endl;
    }

    int Buy(int s_num){
        if (s_num >= 0){
            float s_cost;
            for (int i = 0; i < s_num; i++){
                cout << "Cena priobretennoi akzii nomer " << i + 1 << ": ";
                cin >> s_cost;
                stock_cost_array.push_back(s_cost);
                stock_num++;
            }
        } else{
            return 1;
        }
        return 0;
    }

    int Sell(int s_num){
        if (s_num > 0){
            int ndx;
            for (int i = 0; i < s_num; i++){
                cout << "Nomer prodannoi akzii:: ";
                cin >> ndx;
                ndx++;
                for (int i = ndx; i < stock_num - 1; i++){
                    stock_cost_array[i] = stock_cost_array[i + 1];
                }
                stock_cost_array.pop_back();
                stock_num--;
            }
        } else {
            return 1;
        }
        return 0;
    }

    void Update(int ndx, float cost){
        stock_cost_array[ndx] = cost;
        SetTotal();
    }


    ~Stock() {
        cout << "\nUdalenie dannih destructorom" << endl;
    }
};


int main(){ ///Две компании созданные с помощью конструктора с параметрами и без:
    Stock company1;
    Stock company2("Vtoraya companiya", 2);
    cout << endl;
    company1.Show();
    cout << endl;
    company2.Show();

    return 0;
}
