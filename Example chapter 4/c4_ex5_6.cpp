#include<iostream>
#include<cstring>
#include<windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;
void input(FILE*f, char *s){
    srand(time(NULL));
    int n; cout << "Enter n: "; cin >> n;
    f = fopen(s, "wb");
    putw(n, f);
    for (int i=1; i<=n; i++){
        putw(rand() % 50 , f);
    }
    fclose(f);
}

void output(FILE*f, char* s){
    f = fopen(s, "rb");

    int n = getw(f);
    cout <<"n = " << n  << endl;
    for(int i=0; i < n; i++){
        cout << getw(f) <<" ";
    }
    
    fclose(f);
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    FILE *f; char *s = new char [256]; strcpy(s, "songuyen.inp");
    input(f, s);
    output(f, s);

    
    delete [] s;
    return 0;
}