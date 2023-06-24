#include<iostream>

using namespace std;
int problem_a_recursive(int n){
    if (n == 1 || n == 2) return 1;
    return problem_a_recursive(n-1) + (n-1)*problem_a_recursive(n-2);
}
int problem_a_de_recursion(int n){
    int x, a= 1, b= 1;
    for (int i=3; i <= n; i++){
        x = a +(i-1)*b;
        b = a;
        a = x;
    }
    return x;
}
int main(){
    int n; cout <<"Enter n: "; cin >> n;
    cout << "b: " << problem_a_recursive( n) << endl;
    cout << "c: " << problem_a_de_recursion( n) << endl;

    return 0;
}