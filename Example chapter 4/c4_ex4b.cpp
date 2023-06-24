#include<iostream>
#include<cstring>
using namespace std;

void vietvaofile(FILE*f, char *s){
    f = fopen(s, "w");
    char h;
    do{
        cin >> h;
        fputc(h ,f);
    }while( h != '0');
    fclose(f);
}

int main(){
    FILE* f;
    char *s = new char [256]; strcpy(s, "filechar.out");
    vietvaofile(f,s);
    delete [] s;
    return 0;
}