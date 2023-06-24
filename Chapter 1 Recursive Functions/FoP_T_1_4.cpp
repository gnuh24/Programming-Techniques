#include<iostream>
#include<windows.h>
using namespace std;
int Recursive_Function_F(int n){
	if (n == 1 || n == 2) return 1;
	return Recursive_Function_F(n-1) + Recursive_Function_F(n-2);
}
double Recursive_Function_S(int n){
	if (n == 1) return 1.0/(1 + Recursive_Function_F(1));
	return n*1.0/(1+Recursive_Function_F(n)) + Recursive_Function_S(n-1);
}
int De_recursion_Function_f(int n){
	int f, a =1 , b=1;
	if (n == 1 || n == 2) f = 1;
	for (int i=3; i <= n; i++){
		f = a + b;
		b = a;
		a = f;
	}
	return f;
}
double De_recursion_Function_S(int n){
	double sum = 0;
	for (int i=1; i <= n; i++){
		sum += (1.0*i)/(1+ De_recursion_Function_f(i) );
	}
	return sum;
}
int main(){
	SetConsoleOutputCP(CP_UTF8);
	int n; cout <<"Enter n: "; cin >> n;
	cout << "a) S5 = "<< Recursive_Function_S(5) << endl;
	cout << "b) Recursive: "<< Recursive_Function_S(n) << endl;
	cout << "c) De-recursion: " << De_recursion_Function_S(n) << endl;
	return 0;
}
