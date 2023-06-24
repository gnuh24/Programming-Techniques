#include<iostream>
#include<windows.h>
using namespace std;
double Recursive_Function_x(int n);
double Recursive_Function_y(int n);
void De_recursion_Function_c(int n);

int main(){
    SetConsoleOutputCP(CP_UTF8);
    int n; cout <<" Enter n: "; cin >> n;
    cout <<"x3 = "<< Recursive_Function_x(3) <<" y3 = "<< Recursive_Function_y(3) << endl;
    cout <<"b) Recursive: "<< Recursive_Function_x(n) <<" "<< Recursive_Function_y(n) << endl;
	De_recursion_Function_c(n);
    return 0;
}

double Recursive_Function_y(int n){
    if (n == 0) return 2;
    return 1*Recursive_Function_x(n-1)/5 +  1*Recursive_Function_y(n-1)/7 + 11;
}

double Recursive_Function_x(int n){
    if (n == 0) return 1;
    return 1*Recursive_Function_x(n-1)/3 +  1*Recursive_Function_y(n-1)/2 + 27;
}

void De_recursion_Function_c(int n){
	double x, y, a=1, b=2;
	for (int i = 1; i <= n; i++){
		x = 1*a/3 + 1*b/2 + 27;
		y =  1*a/5 +  1*b/7 + 11;
		a = x;
		b = y;
	}
	cout <<"c) De-recursion: "<< x <<" "<< y << endl;
}

