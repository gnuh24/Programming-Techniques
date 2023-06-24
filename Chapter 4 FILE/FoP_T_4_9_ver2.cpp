/*
Author's information
IG: @gnuh.24
FB: Tuấn Hưng
NOTE!!! FoP_T_4.9_ver2 này là 1 cách làm khác nhưng nó dở hơn FoP_T_4.9
*/ 
#include<iostream>
#include<cstring>
#include<windows.h>
using namespace std;

//a) TÌm từ bên trái của chuỗi 
char *Problem_a_left(char *s){
    return ( strtok(s, " ") );
}
char *Problem_a_right(char *s){
    strrev(s);
    return ( strrev( strtok(s, " ") ) );
}

void Problem_a(FILE *f, char *s, FILE *h, int &n){
    
    f = fopen(s, "r");
    char *str = new char [256];
    fscanf(f, "%d\n", &n);
    fprintf(h, "a) Câu a: Các từ bên phải của mỗi chuỗi: \n") ;
    for(int i=0; i < n; i++){
        fgets(str, 256, f);
        fputs( Problem_a_right(str) , h);
        cout << str;
    }
    fprintf(h, "\n");
    fclose(f);
    
}

//b) Đếm xem trong chuỗi có tổng cộng bao nhiêu từ
int count_word(char *s){
    int count = 0;
    for (int i=0; i < strlen(s) ;i++){
        if ( isspace( s[i] ) )
            count++;
    }
    return count + 1;
}

void Problem_b(FILE*f,char*s, FILE* h, int n){
    f = fopen(s, "r");
    char *str = new char [256];
    fscanf(f, "%d\n", &n);
    int sum = 0;
    for(int i=0; i < n; i++){
        fgets(str, 256, f);
        sum += count_word(str);
       
    }
    fprintf(h, "b) Số từ trong file: %d", sum);
    fclose(f);

}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    char *s = new char [256];  strcpy(s, "str.inp");
    char *h = new char [256];  strcpy(h, "str.out");
    FILE *f_out, *f_in ;
    int n;

    
    f_out = fopen(h, "w");
    Problem_a(f_in,s, f_out, n);
    Problem_b(f_in,s, f_out, n);
    fclose(f_out);
    
    delete [] s, h;
    return 0;
}
/*
Author's information
IG: @gnuh.24
FB: Tuấn Hưng
*/ 