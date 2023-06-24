#include<iostream>
#include<windows.h>
using namespace std;
int greatest_common_divisor(int a, int b){
    int r = a % b;
    while (r > 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}
int gcd(int a,int b){
    if (b == 0) return a;
    return gcd(b, a%b);
}
int main(){
    SetConsoleOutputCP(CP_UTF8);
    int a,b; cout <<"Nhập a b: "; cin >> a >> b;
    cout << greatest_common_divisor(a,b) << endl;
    cout << gcd(a,b);
    return 0;
}

