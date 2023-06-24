/*
Author's information
IG: @gnuh.24
FB: Tuấn Hưng
*/ 
#include<iostream>
#include<cstring>
#include<windows.h>
using namespace std;

void read_file(FILE *f, char *s, char *h){
    f = fopen(s, "r");
    char *str = new char [256];
    fgets(str, 256, f);
    fclose(f);
    f = fopen(h, "wt");
    int count;
    for(char w = 'A'; w <= 'z'; w++){
        count = 0;
        for (int i=0; i < strlen(str); i++){
            if ( str[i] == w)
                count ++;
        }
        if (count > 0){
            fputc(w, f); 
            fprintf(f," %d ",count);
            
        }
    }
    fclose(f);
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    FILE*f; 
    char *s = new char [256]; strcpy(s, "input.txt");
    char *h = new char [256]; strcpy(h, "output.txt");

    read_file(f, s, h);
    delete [] s, h;
    return 0;
}
/*
Author's information
IG: @gnuh.24
FB: Tuấn Hưng
*/ 