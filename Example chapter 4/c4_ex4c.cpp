#include<iostream>
#include<cstring>
using namespace std;

void vietvaofile(FILE*f, char *s){
    f = fopen(s, "w");
    char *k = new char [256];
    int n; cout <<"Etner n: "; cin>> n; cin.ignore();
    for(int i=0; i <n; i++){
        cout << "Line %d: ", i+1; cin.getline(k, 256);
        fputs(k, f); fputc('\n', f);
    }
    fclose(f);
}

int main(){
    FILE* f;
    char *s = new char [256]; strcpy(s, "str.txt");
    vietvaofile(f,s);
    delete [] s;
    return 0;
}