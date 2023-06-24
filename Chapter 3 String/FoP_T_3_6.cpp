#include<iostream>
#include<cstring>
using namespace std;
struct student
{
    long code;
    char *name;
};

void input(char *&s){
    s = new char [256];
    //cout << "Enter string: ";
    fflush(stdin);
    cin.getline(s, 256);
}

void create_list(student *&list, int &n){
    cout << "Enter n: "; cin >> n; cin.ignore();
    list = new student[n];
    for(int i=0; i < n; i++){
        printf("Enter student[%d] code = ", i); cin >> (list+i) -> code ; cin.ignore();
        printf("Enter student[%d] name = ", i); 
        input( (list+i) -> name );
    }
}

void output(student *list, int n){
    for(int i = 0; i < n; i++){
        cout << i+1 << endl;
        cout << "Code: " << (list+i) -> code << endl;
        cout << "Name: " << (list+i) -> name << endl;
    }
}

void swap(int &a, int &b){
    a = a + b;
    b = a - b;
    a = a - b;
}

void swap_name(char *&s, char *&x){
    char* temp = s;
    s = x; 
    x = temp;
}

void InterchangeSort(student *list, int n){
    for(int i=0; i < n-1; i++){
        for(int j=i+1; j < n; j++){
            if ( strcmp( (list+i) -> name , (list+j) -> name) > 0){
                swap( (list+i) ->code, (list+j) ->code);
                swap_name((list+i) ->name, (list+j) ->name);
            }
        }
    }
}

int main(){
    student* list;
    int n;
    create_list(list, n);
    output(list, n);
    InterchangeSort(list, n);
    output(list, n);
    delete [] list;
    return 0;
}//Code được làm bởi THug88 =)) 