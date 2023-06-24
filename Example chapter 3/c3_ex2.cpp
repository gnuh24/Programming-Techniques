#include<iostream>
#include<cstring>
using namespace std;

void input(char *&s){
    s = new char[255];
    fflush(stdin);
    cout <<"Enter string: ";
    cin.getline(s, 255);
}

//a) Xóa khoảng trắng đầu chuỗi, cuối chuỗi, giữa các từ 1 khoảng trắng
char *Problem_a(char *s){
    for(int i=0; i < strlen(s); i++)
        if (isspace(s[i]))
            strcpy(s+i, s+i+1);
    if ( isspace(s[0]) )
        strcpy(s, s+1);
    if (isspace( s[strlen(s) - 1]))
        s[strlen(s) - 1 ] = '\0';
    return s;
}

//b) Tách 1 từ bên trái của chuỗi
// char *Problem_b(char *s){
//     for(int i=0; i < strlen(s); i++){
//         if ( isspace(s[i]) ){
//             s[i] = '\0';
//              break;
//         }
//     }
//     return s;
// }

char *Problem_b(char *s){
    return strtok(s, " ");
}

//c) Tách 1 từ bên phải của chuỗi
char *Problem_c(char *s){
    strrev(s);
    return strrev( strtok(s, " ") );
}

//d) Tìm từ dài nhất
char *Problem_d(char *s){
    char *temp = strtok(s, " "), *string;
    int max = 0;
    while (temp != NULL){
        if (max < strlen(temp) ){
            max = strlen(temp);
            string = temp;
        }
        temp = strtok(NULL, " ");
    }
    return string;
}

//e) Xóa k ký tự bắt đầu từ vị trí p của chuỗi s
char *Problem_e(char *s, int k, int q){
    strcpy(s+q, s+q+k );
    return s;
}

//f) Tìm x trong s nếu thấy thì in ra vị trí không thì in ra -1
int Problem_f(char *s, char *x){
    if ( strstr(s, x) == NULL)
        return -1;
    return strstr(s , x) - s;
}

//g) Đếm xem chuỗi 
int Problem_g(char *s, char *x){
    int count =  0;
    char * temp = s;
    while ( (temp = strstr(temp, x)) != NULL){
        count ++ ;
        temp += strlen(x);
    }
    return count;
}

//h) Chèn chuỗi s2 vào vị trí p của chuỗi s1
char *Problem_h(char*s, char*x, int q){
    char*temp = new char [256];
    strcpy(temp, s+q); // temp = "Tuan Hung";
    strcpy(s+q, x); // s = Ngo Hoang;
    strcpy(s+strlen(s), temp);
    return s;
}
int main(){
    //SetConsoleOutputCP(CP_UTF8);
    char *s, *x;
    input(s);
    cout << s << endl;
    //cout << "a) " << Problem_a(s) << endl;
    cout << "b) " << Problem_b(s) << endl;
    //cout << "c) " << Problem_c(s) << endl;
    //cout << "d) " << Problem_d(s) << endl;
    //cout << "e) " << Problem_e(s,4,3) << endl;
    //input(x);
    //cout << "f) " << Problem_f(s, x) << endl;
    //cout << "g) " << Problem_g(s, x) << endl;
    //cout << "h) " << Problem_h(s, x, 4) << endl;

    delete [] s;
    return 0;
}