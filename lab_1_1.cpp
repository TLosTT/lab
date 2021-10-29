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

    void Acquire(){
        cout << "Vvedite nazvanie companii: " << endl;
        cin >> company_name;

        cout << "Kolichestvo akziy v pakete pervonachalnogo vklada: " << endl;
        cin >> stock_num;

        cout << "Vvedite stoimost kajdoi akzii: " << endl;
        for (int i = 0; i < stock_num; i++){
            int s_cost;
            cout << "Akziya nomer " << i + 1 << ": ";
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
        if (s_num > 0){
            float s_cost;
            for (int i = 0; i < s_num; i++){
                cout << "Cena priobretennoi akzii nomer " << i + 1 << ": ";
                cin >> s_cost;
                stock_cost_array.push_back(s_cost);
                stock_num++;
            }
            SetTotal();
        } else{
            return 1;
        }
        return 0;
    }

    int Sell(int s_num){
        if (s_num > 0){
            int ndx;
            for (int i = 0; i < s_num; i++){
                cout << "Nomer prodannoi akzii: ";
                cin >> ndx;
                for (int i = ndx; i < stock_num - 1; i++){
                    stock_cost_array[i] = stock_cost_array[i + 1];
                }
                stock_cost_array.pop_back();
                stock_num--;
            }
            SetTotal();
        } else {
            return 1;
        }
        return 0;
    }

    void Update(int ndx, float cost){
        stock_cost_array[ndx] = cost;
        SetTotal();
    }

};
void print_menu() {
    cout << "Chto vi hotite sdelat'?" << endl;
    cout << "1. Pokazat' status companii" << endl;
    cout << "2. Cupit' akzii" << endl;
    cout << "3. Prodat' akzii" << endl;
    cout << "4. Obnovit cenu akzii" << endl;
    cout << "5. Exit" << endl;
    cout << ">";
}

int main(){
    Stock Company;
    Company.Acquire();
    int a, kol_akziy, cena;
    bool While=true;
    while (While) {
            print_menu();
            cin >> a;
            switch (a)
            {
            case 1:
            Company.Show();
                break;
            case 2:
            cout<<"Vvedite kolichestvo pokupaemih akziy:";
            cin>>kol_akziy;
            Company.Buy(kol_akziy);
                break;
            case 3:
            cout<<"Vvedite kolichestvo prodnnyh akziy:";
            cin>>kol_akziy;
            Company.Sell(kol_akziy);
                break;
            case 4:
            cout<<"Vvedite nomer obnovlyaemoy akzii:";
            cin>>kol_akziy;
            cout<<"Vvedite cenu obnovlyaemoy akzii:";
            cin>>cena;
            Company.Update(kol_akziy-1, cena);
                break;
            case 5:
                While = false;
                break;
            default:
                cout << "error\n";
                While = false;
                break;
            }
    }
    return 0;
}
