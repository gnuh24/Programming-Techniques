#include<iostream>
using namespace std;
int Recursive_Function_x(int n){
	if ( n == 1) return 1;
	int sum = 0; 
	for (int i=1; i < n; i++){
		sum += Recursive_Function_x(i);
	}
	return n*sum;
}
int Sum_of_n_elements(int x[], int n){
	int sum = 0;
	for (int i=1; i < n; i++){
		sum += x[i];
	}
	return sum;
}
int De_recursive_Function_x(int x[], int n){
	for (int i=2; i < n; i++){
		x[i] = i*Sum_of_n_elements(x,i);
	}
	return n*Sum_of_n_elements(x,n);
}
int main(){
	int n; cout <<"Enter n: "; cin >> n;
	cout <<"a) x7 = " << Recursive_Function_x(7) << endl;
	cout <<"b) Recursive: " << Recursive_Function_x(n) << endl;
	int x[10000]; x[1] = 1;
	cout <<"c) De-recursion: " <<De_recursive_Function_x(x,n) << endl;
	return 0;
}