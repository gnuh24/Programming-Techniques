#include<iostream>
using namespace std;
struct Staff {
    string name;
    int day_of_birth;
    long salary;
    long bonus;
    long thuclanh;

};

void input_list_of_staff(Staff *&a, int &n);
void output(Staff *a, int n);
void swap(Staff *a, Staff *b);
void decrease(Staff *&a, int n);

int main(){
    Staff *a; int n;
    input_list_of_staff(a,n);
    output(a,n);
    decrease(a,n);
    output(a,n);
    return 0;
}
void input_list_of_staff(Staff *&a, int &n){
    cout << "Enter n = "; cin >> n;
    a = new Staff[n];
    for (int i=0; i < n; i++){
        cin. ignore();
        cout <<"Enter the staffs' name: " ; getline(cin, (a+i) -> name );
        cout <<"Enter the day of birth: "; cin >> (a+i) -> day_of_birth;
        cout <<"Enter the salary: "; cin >> (a+i) -> salary;
        cout <<"Enter the bonus: "; cin >> (a+i) -> bonus;
        (a+i) -> thuclanh = (a+i) -> salary + (a+i) -> bonus;
    }
}

void output(Staff *a, int n){
    for (int i=0; i < n; i++){
        cout << "Name: " << (a+i) -> name << endl;
        cout << "Day of birth: " << (a+i) -> day_of_birth<< endl;
        cout << "Salary: " << (a+i) -> salary << endl;
        cout << "Bonus: " << (a+i) -> bonus << endl;
        cout << "Thuclanh: " << (a+i) -> thuclanh << endl;
        cout << endl;
    }
}

void swap(Staff *a, Staff *b){
    Staff temp = *a;
    *a = *b;
    *b = temp;
}

void decrease(Staff *&a, int n){
    for (int i=0; i < n-1; i++){
        for (int j=i+1; j<n; j++){
            if ( (a+i) -> thuclanh < (a+j) -> thuclanh){
                swap((a+i), (a+j));
            }
        }
    }
}