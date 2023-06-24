#include<iostream>
#include<windows.h>
using namespace std;
int power(double x, int n);
int main(){
    SetConsoleOutputCP(CP_UTF8);
    double x; int n; cout <<"Nhập x n: "; cin >> x >> n;
    cout << power(x,n) << endl;
    
    return 0;
}

int power(double x, int n){
    if (n == 0) return 1;
    return x*power(x,n-1);
}
