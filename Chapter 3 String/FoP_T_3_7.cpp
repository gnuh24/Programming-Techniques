#include<iostream>
#include<cstring>
#include<windows.h>
using namespace std;
struct DayOfBirth
{
    long long day;
    long long month;
    long long year;
};


struct staff
{
    long long code;
    char *name;
    DayOfBirth birthday;
    long long salary;
    long long bonus;
    long long take_home_pay;
};

void input(char *&s){
    s = new char [256];
    cin.getline(s, 256);
}

//a) Nhập vào hồ sơ của n nhân viên với các thông tin: mã nhân viên, họ và tên, ngày sinh, lương cơ bảm, thưởng, thực lãnh.
void enter_the_informations_of_staffs(staff *list){
    cout << "Code: "; cin >> list  -> code; cin.ignore();
    cout << "Name: "; input( list  -> name );
    cout << "Day: "; cin >>  ( list  -> birthday).day;
    cout << "Month: "; cin >> ( list  -> birthday).month;
    cout << "Year: "; cin >> ( list  -> birthday).year;
    cout << "Salary: "; cin >> list  -> salary; 
    cout << "Bonus: "; cin >> list  -> bonus; cin.ignore();
    list ->take_home_pay = list ->bonus + list ->salary;
}
void create_list_of_staff(staff *&list, int &n){
    cout << "Enter n = "; cin >> n; cin.ignore();
    list = new staff[n];
    for(int i=0; i < n; i++){
        cout << i + 1 << endl;
        enter_the_informations_of_staffs(list+i);
    }
}

void output(staff *list, int n){
    for(int i=0; i < n; i++){
        cout << i + 1 << endl;
        cout << "Code: "; cout << (list + i) -> code << endl; 
        cout << "Name: "; cout << (list + i) -> name  << endl;
        cout << "Day: "; cout <<  ( (list + i) -> birthday).day << endl;
        cout << "Month: "; cout <<  ( (list + i) -> birthday).month << endl;
        cout << "Year: "; cout <<  ( (list + i) -> birthday).year << endl;
        cout << "Salary: "; cout << (list + i) -> salary << endl; 
        cout << "Bonus: "; cout << (list + i) -> bonus  << endl;
        cout << "Take-home pay: "; cout << (list + i) -> take_home_pay  << endl;
    }
}

void swap(staff &a, staff &b){
    staff temp = a;
    a = b;
    b = temp;
}

//Code được làm bởi THug88 =)) 
void Sort_the_list_acording_to_the_salary(staff *list, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if((list + i)->salary < (list + j)->salary){
                swap(*(list + i), *(list + j));
            }
        }
    }
}

void Sort_the_list_acording_to_the_code(staff *list, int n){
    for(int i = 0; i < n-1 ; i++){
        for(int j = i + 1; j < n; j++){
            if ( (list+i) -> code >  (list+j) -> code)  {
                swap(*(list + i), *(list + j));
            }
        }
    }
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    staff *list_of_staff;
    int n;
    create_list_of_staff(list_of_staff, n);
    output(list_of_staff, n);
    //Sort_the_list_acording_to_the_salary(list_of_staff, n);
    //output(list_of_staff, n);

    //Sort_the_list_acording_to_the_code(list_of_staff, n);
    //output(list_of_staff, n);

    delete [] list_of_staff;
    return 0;
}