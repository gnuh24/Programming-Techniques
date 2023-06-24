#include<iostream>
#include<cstring>
#include<windows.h>
using namespace std;
struct HoSo{
    char code[6];
    char name[32];
    int salary;
    int bonus;
    int takeHomePay;
};

void input_in4(HoSo *Student){
    cout <<"Code: "; cin.getline(Student ->code, 6);
    cout <<"Name: "; cin.getline(Student ->name, 32);
    cout <<"Salary: "; cin >> Student -> salary;
    cout <<"Bonus: "; cin >> Student -> bonus; cin.ignore();
    Student -> takeHomePay = Student -> salary + Student -> bonus;
}

void output_in4(HoSo *Student){
    cout <<"Code: "<< Student ->code << endl;
    cout <<"Name: "<< Student ->name<< endl;
    cout <<"Salary: "<< Student ->salary << endl;
    cout <<"Bonus:" << Student -> bonus<< endl;
    cout <<"Take-home pay: " << Student ->takeHomePay << endl;
}


void Problem_a(FILE *f, char *s){
    f = fopen(s, "wb");
    int n; cout <<"Số lượng = "; cin >> n; cin.ignore();
    HoSo *Student = new HoSo;
    for(int i=0; i < n; i++){
        cout <<"Hồ sơ "<< i+1 << endl;
        input_in4(Student);
        fwrite(Student, sizeof(HoSo), 1, f);
    }
    delete Student;
    fclose(f);
}


void Problem_b(FILE*f, char *s){
    f = fopen(s, "rb");
    HoSo *Student = new HoSo;
    int serial = 1;
    while ( fread(Student, sizeof(HoSo), 1, f) == 1){
        cout << serial++ << endl;
        output_in4(Student);
    }
    fclose(f);
}


void Problem_c(FILE *f, char *s){
    int sum = 0;
    f = fopen(s, "rb");
    HoSo *Student = new HoSo;
    while ( fread(Student, sizeof(HoSo), 1, f) == 1 ){ //fread trả về số lượng dữ liệu đọc được vd đọc dc 1 block dữ liệu thì return 1 còn không thì return 0
        sum += Student -> takeHomePay;
    }
    cout << "c) Tổng thực lãnh: " << sum << endl;
    fclose(f);
}


void copyHoSo(HoSo *A, HoSo *B){
    strcpy(A -> code, B -> code);
    strcpy(A -> name, B -> name);
    A -> salary = B -> salary;
    A -> bonus = B -> bonus;
    A -> takeHomePay = A -> salary + A -> bonus;
}

void Problem_d_e(FILE *f, char *s, int &count){
    
    f = fopen(s, "rb");
    HoSo *Student = new HoSo;
    count++; 
    fread(Student, sizeof(HoSo), 1, f);
    HoSo *max = new HoSo;
    copyHoSo(max, Student);
    while ( fread(Student, sizeof(HoSo), 1, f) == 1){
        count++;
        if ( max -> salary < Student -> salary)
            copyHoSo(max, Student);
    }

    cout << "d) Lương cao nhất: " << max -> name << endl;
    cout << "e) Số hồ sơ trong file: " << count << endl;
    fclose(f);
}

void CreateList(FILE *f, char *s, HoSo *list, int count){
    f = fopen(s, "rb");
    fread(list, sizeof(HoSo), count, f);
    fclose(f);
}

void Swap(HoSo &A, HoSo &B){
    HoSo temp = A;
    A = B;
    B = temp;
}

void BubbleSort(HoSo *list, int count ){
    for(int stop = 0; stop < count - 1; stop ++){
        for(int target = count - 1; target > stop; target --){
            if ( (list + target) -> takeHomePay < (list + target - 1) -> takeHomePay){
                Swap( *(list+target) , *(list + target - 1 ) );
            }
        }
    }
}

void Problem_f(FILE *f, char *h, HoSo *list, int count){
    f = fopen(h, "wb");
    fwrite(list, sizeof(HoSo), count, f);
    fclose(f);
}
void output(HoSo *list, int count){
    for(int i=0; i < count; i++){
        output_in4(list+i);
    }
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    FILE *f;
    char *s = new char [256]; strcpy(s, "hoso.dat");
    char *h = new char [256]; strcpy(h, "hoso.txt");
    Problem_a(f, s);
    Problem_b(f, s);
    Problem_c(f, s);
    int count = 0;
    Problem_d_e(f, s, count);
    HoSo *list = new HoSo [count];
    CreateList(f,s,list,count);
    BubbleSort(list, count);
    Problem_f(f, h, list, count);
    Problem_b(f, h);
    delete [] s, h, list;
    return 0;
}