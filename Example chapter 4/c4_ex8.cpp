#include<iostream>
#include<cstring>
#include<windows.h>
using namespace std;
struct Student
{
    char code[10];
    char name[40];
    int score;
};
void input_in4(Student *hocsinh){
    cout << "MSSV: "; cin.getline(hocsinh->code, 10);
    cout << "Name: "; cin.getline(hocsinh->name, 40);
    cout << "Score: "; cin >> hocsinh->score; cin.ignore();
}

//a) Nhập vào file nhị phân
void Problem_a(FILE* f, char *s){
    f = fopen(s, "wb");
    int n; cout << "Nhập số lượng n = "; cin >> n; cin.ignore();
    Student *HocSinh = new Student;
    for(int i =0; i < n ; i ++){
        cout << i << endl;
        input_in4(HocSinh);
        fwrite(HocSinh, sizeof(Student), 1, f);
    }
    fclose(f);
}

//b) Xuất hồ sơ
void output_in4(Student *hocsinh){
    cout << "Code: " << hocsinh->code << endl;
    cout << "Name: " << hocsinh->name << endl;
    cout << "Score: " << hocsinh->score << endl;
}

void Problem_b(FILE* f, char *s){
    f = fopen(s, "rb");
    Student *hoso = new Student;    
    while ( fread(hoso, sizeof(Student), 1, f) == 1 ){
        output_in4(hoso); 
    }
    fclose(f);
}

//c) Nhập thêm hồ sơ
void Problem_c(FILE *f, char *s){
    int n; cout <<"Nhập số sinh viên bạn muốn thêm vào: "; cin >> n ; cin.ignore();
    Student *SinhVien = new Student;
    f = fopen(s, "ab");
    for(int i=0; i <n; i++){
        input_in4(SinhVien);
        fwrite(SinhVien, sizeof(Student), 1, f);
    }
    fclose(f);
}

//d) Tìm kiếm theo mã số sinh viên

void Problem_d(FILE* f, char* s) {
    f = fopen(s, "rb");
    char *target = new char [10];
    cout << "Nhập mã số sinh viên bạn muốn tìm: ";
    cin.getline(target, 10);
    bool flag = false;
    Student* SinhVien = new Student;
    while ( fread(SinhVien, sizeof(Student), 1, f) == 1 && flag == false) {
        if (strcmp(SinhVien->code, target) == 0) {
            cout << "Họ tên: " << SinhVien->name << endl;
            flag = true;
        }
    }
    if (flag == false) {
        cout << "Không tìm thấy sinh viên nào có mã số " << target << endl;
    }
    fclose(f);
}

//e) Tìm sinh viên có điểm cao nhất
void Problem_e(FILE *f, char *s){
    f = fopen(s, "rb");
    Student* SinhVien = new Student;
    fread(SinhVien, sizeof(Student),1,f);
    Student* max = new Student;
    //output_in4(SinhVien);
    strcpy(max -> code, SinhVien -> code);
    strcpy(max -> name, SinhVien -> name);
    max -> score = SinhVien -> score;
    while ( fread(SinhVien, sizeof(Student),1,f) == 1){
        if ( max -> score < SinhVien -> score){
            strcpy(max -> code, SinhVien -> code);
            strcpy(max -> name, SinhVien -> name);
            max -> score = SinhVien -> score;
        }
    }
    cout <<"Sinh viên có điểm cao nhất là: " << max -> name <<" với số điểm " << max -> score;
    fclose(f);
}

//f) Đổ dữ liệu ra mảng list
void output(Student *list, int n){
    for(int i=0; i < n ; i ++){
        output_in4( list + i );
    }
}
void Problem_f(FILE *f, char *s, Student *&list, int &n){
    f = fopen(s, "rb");
    int serial = 0;
    while ( fread(list + serial, sizeof(Student) ,1 ,f) == 1 ){
        serial ++;
    }
    n = serial;
    fclose(f);
    output(list, n);
}

void menu(FILE* f, char *s, Student *&list, int &n){
    cout << "Hãy nhập sự lựa chọn của bạn: \n   1. Nhập hồ sơ\n   2. Xuất hồ sơ\n   3. Nhập thêm hồ sơ\n   4. Tìm kiếm theo mã số sinh viên\n   5. Tìm kiếm điểm cao nhất\n   6. Đọc file nhị phân ra mảng\n";
    int choice; cin >> choice; cin.ignore();
    switch (choice)
    {
    case 1:
        Problem_a(f, s);
        break;
    case 2:
        Problem_b(f, s);
        break;
    case 3:
        Problem_c(f, s);
        break;
    case 4:
        Problem_d(f, s);
        break;
    case 5:
        Problem_e(f, s);
        break;
    case 6:
        Problem_f(f, s, list, n);
        break;
    }

}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    FILE* f ;
    int n;
    Student *list = new Student [10];
    char *s = new char [256]; strcpy(s, "hosohs.txt");
    menu(f, s, list, n);
    delete [] list, s;
    return 0;
}