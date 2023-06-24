/*
Author's information
IG: @gnuh.24
FB: Tuấn Hưng
*/ 
#include<iostream>
#include<cstring>
#include<windows.h>
using namespace std;
struct PARAGRAPH
{
    char *sentence;
};

void read(FILE *f, char *s, PARAGRAPH*&doanVan, int &n){
    f = fopen(s, "r");
    fscanf(f, "%d\n", &n);
    doanVan = new PARAGRAPH [n];
    for (int i=0; i < n; i++){
        (doanVan + i) -> sentence = new char [256];
        fgets( (doanVan + i) -> sentence, 256, f );
    }
    fclose(f);
}


//a) TÌm từ bên trái của chuỗi 
char *Problem_a_left(char *s){
    return ( strtok(s, " ") );
}

char *Problem_a_right(char *s){
    strrev(s);
    return ( strrev( strtok(s, " ") ) );
}

void Problem_a(FILE *f, PARAGRAPH* doanVan ,int &n){
    fprintf(f, "a) Câu a: Các từ bên phải của mỗi chuỗi: \n") ;
    int i=0; char *temp = new char [256];
    while ( i < n ){
        strcpy(temp, (doanVan + i) -> sentence);
        fputs( Problem_a_right(temp), f ); //fputs mà lấy từ bên phải ngoài cùng sẽ lấy luôn "\n" theo
        i++; 
    }
    fprintf(f, "\n");
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

void Problem_b(FILE*f, PARAGRAPH *doanVan, int n){
    int sum = 0;
    for(int i=0; i < n; i++){
        sum += count_word( (doanVan + i) -> sentence );   
    }
    fprintf(f, "b) Số từ trong file: %d", sum);
}
void delete_list(PARAGRAPH *doanVan, int n){
    for (int i=0; i < n; i++){
        delete [] ( doanVan + i ) -> sentence;
    }
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    char *s = new char [256];  strcpy(s, "str.inp");
    char *h = new char [256];  strcpy(h, "str.out");
    FILE *f;
    PARAGRAPH* doanVan;
    int n;

    read(f, s, doanVan, n);
    f = fopen(h, "w");
    Problem_a(f, doanVan, n);
    Problem_b(f, doanVan, n);

    delete_list(doanVan, n);
    delete [] s, h, doanVan;
    return 0;
}
/*
Author's information
IG: @gnuh.24
FB: Tuấn Hưng
*/ 