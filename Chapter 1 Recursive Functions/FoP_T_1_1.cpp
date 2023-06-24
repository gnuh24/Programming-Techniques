#include<iostream>
#include<windows.h>
using namespace std;
int Problem_a_Recursive(int n){
    if (n == 1 ) return 1;
    return n + Problem_a_Recursive(n-1);
}
int Problem_a_De_Recursive(int n){
    int sum = 0;
    for (int i=1; i <= n; i++){
        sum += i;
    }
    return sum;
}
int Problem_b_Recursive(int n){
    if (n == 1) return 1;
    return n*n + Problem_b_Recursive(n-1);
}

int Problem_c_Recursive(int n){
    if (n == 1) return 1;
    else{
        int product = 1;
        for (int i=1; i <= n; i++ ){
            product*=i;
        }
        return product + Problem_c_Recursive(n-1);
    }
}
int Problem_d_Recursive(int n){
    if (n == 1) return 2;
    else{
        int product = 1;
        for (int i=n; i <= 2*n; i++){
            product *= i;
        }
        return product + Problem_d_Recursive(n-1);
    }
}
int main(){
    SetConsoleOutputCP(CP_UTF8);
    int n;
    cout <<"Input n: "; cin >> n;
    cout <<"a) Recursive: " << Problem_a_Recursive(n) << endl;
    cout <<"a) De-Recursion: " << Problem_a_De_Recursive(n) << endl;
    cout <<"b) Recursive: " << Problem_b_Recursive(n) << endl;
    cout <<"c) Recursive: " << Problem_c_Recursive(n) << endl;
    cout <<"d) Recursive: " << Problem_d_Recursive(n) << endl;

  
    return 0;
}