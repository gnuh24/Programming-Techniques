// 0) Xuất file lên màn hình
// a) File này chứa bao nhiêu chuỗi?  10 chuỗi
// b) Tìm chiều dài của mỗi chuỗi  78 206 226 204 118 91 265 66 91 60
// c) Tìm chuỗi có chiều dài dài nhất
// d) Đếm xem mỗi chuỗi có bao nhiêu từ. 9 36 42 37 21 17 48 12 16 8
// e) Hỏi file này có bao nhiêu từ 246
// f) 
// g)
// h)
// i)
// j) 

#include<iostream>
#include<windows.h>
#include<cstring>
#define MAX 1000
using namespace std;

// Xuất file lên màn hình
void Problem_0(FILE *f, char *s){
    f = fopen(s, "r");
    char *str = new char [MAX];
    while ( !feof(f) )
        cout << fgets(str, MAX, f) <<endl;
    cout << endl;
    fclose(f);
}

// a) File này chứa bao nhiêu chuỗi?
int Problem_a(FILE *f, char *s){
    f = fopen(s, "r");
    char *str = new char [MAX];
    int count = 0;
    while ( !feof(f) ){
        fgets(str, MAX, f) ;
        count++;
    }
    fclose(f);
    return count;
}

// b) Tìm chiều dài của mỗi chuỗi
void Problem_b(FILE *f, char *s){
    f = fopen(s, "r");
    char *str = new char [MAX];
    while ( !feof(f) ){   
        cout << strlen(fgets(str, MAX, f))  <<" "; 
    }
    fclose(f);
}

// c) Tìm chuỗi có chiều dài dài nhất
char* Problem_c(FILE *f, char *s){
    f = fopen(s, "r");
    char *str = new char [MAX], *strMAX = new char [MAX]; strcpy(strMAX, "");
    while ( !feof(f) )
    {
        if ( strlen(strMAX) < strlen( fgets(str, MAX, f) ) ){
            strcpy(strMAX, str);
        }
    }
    fclose(f);
    return strMAX;
}

// d) Đếm xem mỗi chuỗi có bao nhiêu từ
int count_word(char *s){
    int count = 0;
    for(int i=0; i < strlen(s); i++){
        if ( s[i] == ' ')
            count++;
    }
    return count + 1;
}

void Problem_d(FILE *f, char *s){
    f = fopen(s, "r");
    char *str = new char [MAX];
    while ( !feof(f)){
        cout << count_word( fgets(str, MAX, f) ) <<" ";
    }
    cout << endl;
    fclose(f);
}

// e) Hỏi file này có bao nhiêu từ
int Problem_e(FILE *f, char *s){
    int word = 0;
    f = fopen(s, "r");
    char *str = new char [MAX];
    while ( !feof(f) ){
        word += count_word( fgets(str, MAX, f) );
    }
    fclose(f);
    return word;
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    char *s = new char [MAX]; strcpy(s, "strE.txt");    

    FILE *f;
    Problem_0(f, s);
    //cout <<"a) Số chuỗi trong file là: " <<Problem_a(f, s) << endl;
    cout <<"b) Tìm chiều dài của mỗi chuỗi: " ; Problem_b(f, s);
    //cout <<"c) Chuỗi dài nhất: " << Problem_c(f, s) << endl;
    //cout <<"d) Đếm xem mỗi chuỗi có bao nhiêu từ: "; Problem_d(f, s);
    //cout <<"e) Số lượng từ trong file: " << Problem_e(f, s) << endl;
    return 0;

}