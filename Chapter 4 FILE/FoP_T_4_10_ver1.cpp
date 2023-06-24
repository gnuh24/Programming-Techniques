/*
Author's information
IG: @gnuh.24
FB: Tuấn Hưng
Cách 1: Đổ vào struct rồi thao tác 
*/ 
#include<iostream>
#include<cstring>
#include<windows.h>
using namespace std;
struct PARAGRAPH
{
    char *sentence;
};
//Hàm đọc file và lưu các thông tin vào cấu trúc dữ liệu PARAGRAPH
void readFile(FILE *f, char* s, PARAGRAPH *&doanVan, int &n){
    f = fopen(s, "r");
    fscanf(f, "%d\n", &n);
    //cout << n << endl;
    doanVan = new PARAGRAPH [n];
    for(int i=0; i< n; i++){
        (doanVan + i) -> sentence = new char [256];
        fgets((doanVan + i) -> sentence, 256, f );
        //cout << (doanVan + i) -> sentence;
    }
    fclose(f);
}
//Hàm xóa list
void delete_list(PARAGRAPH *doanVan, int n){
    for (int i=0; i < n; i++){
        delete [] ( doanVan + i ) -> sentence;
    }
}

//a) Tìm từ dài nhất trong mỗi câu
char* FindTheLongestWord(char *s){
    char *temp = new char [256]; strcpy(temp, s);
    char* token = strtok(temp, " ");
    char *max = token;
    while ( token != NULL){
        if ( strlen(max) < strlen(token) ){
            max = token;
        }
        token = strtok(NULL, " ");
    }
    return max;
}

void Problem_a(FILE *f, PARAGRAPH* doanVan, int n){
    fprintf(f, "a) Các từ dài nhất trong mỗi chuỗi: \n");
    for(int i=0; i <n; i++){    
        fputs(FindTheLongestWord( (doanVan+i) -> sentence ) , f); fputs("\n", f);
    }
    fprintf(f, "\n");
}

//b) in từ bên trái và phải mỗi chuỗi
char *Problem_b_left(char *s){
    char * temp = new char [256]; strcpy(temp, s); 
    //Nếu không tạo biến tạm thì khi truyền s vào và sau khi xuất hàm xong s cũng sẽ thay đổi
    return ( strtok(temp, " ") );
}
char *Problem_b_right(char *s){
    char * temp = new char [256]; strcpy(temp, s);
    strrev(temp);
    return ( strrev( strtok(temp, " ") ) );
}
void Problem_b(FILE*f, PARAGRAPH*doanVan, int n){
    fprintf(f, "b) Từ bên trái ngoài cùng và từ bên phải ngoài cùng của mỗi chuỗi: \n");
    for(int i=0; i<n; i++){
        fputs( Problem_b_left((doanVan + i) -> sentence), f);
        fputs( " ", f);
        fputs( Problem_b_right((doanVan + i) -> sentence), f);
    }
    fprintf(f, "\n");
}

//c) Tìm chuỗi dài nhất
void Problem_c(FILE *f, PARAGRAPH *doanVan, int n){
    char *max = (doanVan + 0) -> sentence;
    
    for(int i=0; i < n; i++){
        if ( strlen((doanVan + i) -> sentence) > strlen(max) ){
            max = (doanVan + i) -> sentence;
        } 
    }
    fprintf(f, "c) Chuỗi dài nhất trong file: "); fputs(max, f); fputs("\n",f);
}

//d) Đếm xem trong file có bao nhiêu từ
int count_word(char *s){
    int count = 0;
    for (int i=0; i < strlen(s) ;i++){
        if ( isspace( s[i] ) )
            count++;
    }
    return count + 1;
}
void Problem_d(FILE*f, PARAGRAPH *doanVan, int n){
    int sum = 0;
    for(int i =0; i < n; i++){
        sum += count_word( (doanVan + i) -> sentence );
    }
    fprintf(f, "d) Số lượng từ trong file là: %d\n", sum);
}

//e)  Đếm xem file này có bao nhiêu từ your
int check_your(char *s){
    char *temp = new char [256]; strcpy(temp, s);
    int count = 0;
    temp = strstr(temp, "your");
    while (temp != NULL){
        if ( (temp + strlen("your"))[0] == ' ' ) //Nếu không có if này thì các từ như yourself đều sẽ được tính vào
            count++;
        strcpy(temp, temp + strlen("your")); 
        temp = strstr(temp, "your");
    }
    return count;
}
void Problem_e(FILE *f, PARAGRAPH * doanVan, int n){
    int count = 0;
    for(int i=0; i <n; i++){
        count += check_your((doanVan + i) -> sentence);
        cout << count << " ";
    }
    fprintf(f, "e) Số lượng từ your trong file: %d", count); 
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    char *s = new char [256]; strcpy(s, "str.inp");
    char *h = new char [256]; strcpy(h, "str.out");
    PARAGRAPH *doanVan;
    FILE *f; int n;
    readFile(f,s, doanVan, n);

    f = fopen(h, "w");
    Problem_a(f, doanVan, n);
    Problem_b(f, doanVan, n);
    Problem_c(f, doanVan, n);
    Problem_d(f, doanVan, n);
    Problem_e(f, doanVan, n);

    fclose(f);
    delete [] s,h, doanVan;
    return 0;
}
/*
Author's information
IG: @gnuh.24
FB: Tuấn Hưng
*/ 