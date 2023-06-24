#include<iostream>
#include<cstring>
#include<windows.h>
using namespace std;

//a) Đếm xem trong chuỗi có bao nhiêu ký tự hoa và bao nhiêu ký tự thường.
void Problem_a(char *s){
    cout << "a) ";
    int upper = 0, lower = 0;
    for(int i=0; i < strlen(s); i++){
        if ( isupper(s[i]) ) upper++;
        if ( islower(s[i]) ) lower++;
    }
    cout << upper <<" " << lower << endl;
}

//b) Chuyển từng ký tự sang ascii 
void Problem_b(char *s){
    cout << "b) ";
    for(int i=0; i < strlen(s); i++){
        cout << int(s[i]) << " "; // Hoặc cout << toascii(s[i]) << " ";
    }
    cout << endl;
}

//c) Chuyển các ký tự đầu thành chữ in hoa còn lại thường hết ^^
void Problem_c(char *s){
    cout << "c) ";
    strlwr(s);
	for (int i=0;i<strlen(s);i++)
	if (isspace(s[i]))
		s[i+1]=toupper(s[i+1]);
	s[0]=toupper(s[0]);
    cout << s << endl;
}

//d) Đếm số lượng từ của chuỗi s
int Problem_d(char *s){
    if (s == NULL) return 0;
    int count = 1;
    for(int i=0; i < strlen(s); i++){
        if (isspace(s[i]))
            count++;
    }
    return count;
}
//e) Đếm số lượng ký tự mỗi từ
void Problem_e(char *s){
    if (s == NULL) 
        cout << 0;
    else{
        cout << "e) Đếm số lượng ký tự của mỗi từ: ";
        int count = 0;
        for(int i=0; i < strlen(s); i++){
            if ( isspace(s[i]) ){
                cout << count <<" ";
                count = 0;
            }
            else
                count++;
        }
        cout << count;
    }
    cout << endl;
}

//f) Từ dài nhất có bao nhiêu ký tự
int Problem_f(char *s){
    //The longest word
    int longest_word = 0, count = 0;
    for(int i=0; i < strlen(s); i++){
        if ( isspace( s[i] ) ){
            if ( longest_word < count)
                longest_word = count;
            count = 0;
        }
        else
            count++;
    }
    if ( longest_word < count)
        longest_word = count;
    return longest_word;
}

//g) Sắp xếp các ký tự theo chiều tăng dần của mã ASCII 
void Problem_g(char *s){
    cout << "g) ";
    for(int i=0; i < strlen(s) - 1; i++)
        for(int j = i+1; j < strlen(s); j++)
            if( int(s[j]) <  int(s[i]))
                swap(s[j], s[i] );
    cout << s << endl;
}

//h) Tần suất xuất hiện của các ký tự
void Problem_h(char *s){
    cout <<"h) ";
    
    int frequency = 1;
    Problem_g(s);
    for(int i=0; i < strlen(s); i++){
        if ( s[i] != s[i+1] ){
            cout << s[i] <<" = " <<frequency << endl;
            frequency = 1;
        }
        else
            frequency++;
    }

    cout << endl;
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    char *s;
    s = new char[255];
    cin.getline(s,255);
    cout << s << endl;
    Problem_a(s);
    Problem_b(s);
    Problem_c(s);
    cout << "d) " << Problem_d(s) << endl;
    Problem_e(s);
    cout << "f) " << Problem_f(s) << endl;
    Problem_g(s);
    Problem_h(s);
    delete[] s;
    return 0;
} 