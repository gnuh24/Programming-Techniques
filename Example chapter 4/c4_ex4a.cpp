#include<iostream>
#include<cstring>
#include<windows.h>
using namespace std;

void Problem_a(FILE* f, char *s){
    f = fopen(s, "r");
    char k;
    while( !feof(f) ){
        k = fgetc(f);
        cout << int(k) << " ";
    }
    cout << endl;
    fclose(f);
}

//b) File chứa bao nhiêu ký tự 
int Problem_b(FILE* f, char *s){
    f = fopen(s, "r");

    int count = 0; char k;
    while ((k = fgetc(f)) != EOF) {
        if (k != ' ' && k != '\t' && k != '\n') {
            count++;
        }
    }
    fclose(f);

    return count;
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    char *s = new char [256]; strcpy(s, "filechar.inp");
    FILE* f;
    Problem_a(f,s);
    cout << "b) Số lượng ký tự: " << Problem_b(f, s);
    return 0;
}