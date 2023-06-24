#include<iostream>
#include<cstring>
#include<windows.h>
using namespace std;

struct candidates
{
    char* code;
    char* name;
    float foreign_language_mark; //Diem ngoai ngu
    float basic_subjects_mark;
    float foundation_subjects_mark;
    float total;
};

void input(char *&s){
    s = new char[256];
    cin.getline(s, 256);
}

void enter_candidates_in4(candidates *list, int serial){
    cout << serial +1 << endl;
    cout << "Code: "; input( (list + serial) -> code);
    cout << "Name: "; input( (list + serial) -> name);
    cout << "Điểm môn ngoại ngữ: "; cin >> (list + serial) -> foreign_language_mark;
    cout << "Điểm môn cơ bản: "; cin >> (list + serial) -> basic_subjects_mark;
    cout << "Điểm môn cơ sở: "; cin >> (list + serial) -> foundation_subjects_mark; cin.ignore();
    (list + serial) -> total = (list + serial) -> foreign_language_mark + (list + serial) -> basic_subjects_mark + (list + serial) -> foundation_subjects_mark;

}

void create_list(candidates *&list, int &n){
    cout <<"Enter n = "; cin >> n; cin.ignore();
    list = new candidates[n];
    for(int i=0; i<n; i++){
        enter_candidates_in4(list, i);
    }
}

void output_per(candidates *list, int serial){
    cout << serial +1 << endl;
    cout << "Code: "<< (list + serial) -> code  << endl;
    cout << "Name: "<< (list + serial) -> name  << endl;
    cout << "Điểm môn ngoại ngữ: "<< (list + serial) -> foreign_language_mark << endl;
    cout << "Điểm môn cơ bản: "<< (list + serial) -> basic_subjects_mark << endl;
    cout << "Điểm môn cơ sở: "<< (list + serial) -> foundation_subjects_mark << endl;
    cout << "Điểm tổng: " << (list + serial) -> total << endl;
}

void output(candidates *list, int n){
    for(int serial = 0; serial < n; serial++){
        output_per(list, serial);
    }
}

//a) Tìm xem có thí sinh nào dưới 5đ không thì in ra
void Problem_a(candidates *list, int n){
    cout << "a) Các thí sinh có môn dưới 5đ" << endl;
    for(int i=0; i < n; i ++){
        if ( (list+i) -> foreign_language_mark < 5 || (list+i) -> basic_subjects_mark < 5 || (list+i) -> foundation_subjects_mark < 5 ){
            output_per(list, i);
        }
    }
}

//b) Đếm xem có bao nhiêu thí sinh toàn bộ môn trên 5 và tổng điểm môn cơ sở và môn cơ bản trên 12
int Problem_b(candidates *list, int n){
    int count = 0;
    for(int i=0; i < n; i++)
        if ((list + i) -> basic_subjects_mark +(list + i) -> foundation_subjects_mark >= 12 &&  (list + i) -> basic_subjects_mark >= 5 && (list + i) -> foundation_subjects_mark >= 5 && (list + i) -> foreign_language_mark >= 5)
            count++;
    return count;
}

//c) Tìm kiếm những thí sinh có tổng điểm 3 môn cao nhất
void Problem_c(candidates *list, int n){
    cout << "c) Thí sinh có điểm cao nhất: ";
    candidates max = *(list+0); int index = 0;
    for(int i=1; i < n; i++){
        if ( (list + i) -> total > max.total ){
            max = *(list + i);
            index = i;
        }
    }
    output_per(list, index);
}



//d) Tìm kiếm thông tin thí sinh có mã là x
void Problem_d(candidates *list, int n, char* x){
    cout << "d) Thông tin thí sinh có mã số sinh viên " << x << endl;
    for(int i=0; i < n ; i++)
        if ( strcmp( (list+i) -> code, x) == 0){
            output_per(list, i);
            return;
        }
}



//e) Sắp xếp theo chiều tăng dần của code
void swap(candidates &a, candidates &b){
    candidates temp = a;
    a = b;
    b = temp;
}

void Problem_e(candidates *list, int n){
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if ( strcmp( (list+i) -> code, (list+i) -> code) > 0)
                swap( *(list+i), *(list+j));
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    candidates *list;
    int n;
    create_list(list, n);
    output(list, n);
    Problem_a(list, n);
    cout << "b) Các thí sinh có tất cả các điểm trên 5 và điểm trung bình môn cơ bản và cơ sở trên và bằng 12: " << endl;
    cout << Problem_b(list, n) << endl;
    Problem_c(list, n);
    char *x = new char [256];
    strcpy(x, "3122560028");
    Problem_d(list, n, x);
    Problem_e(list, n );
    cout << "e) Sắp xếp danh sách theo thứ tự code: ";
    output(list, n);
    delete[] list;
    return 0;
}//Code được làm bởi THug88 =)) 