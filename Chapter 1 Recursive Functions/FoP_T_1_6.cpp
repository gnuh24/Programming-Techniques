#include<iostream>
using namespace std;


int Recursive_Function_x(int n){
	if ( n == 0 || n == 1 ) return 1;
	int sum = 0, k = n;
	for (int i=0; i < n; i++){
		sum += k*Recursive_Function_x(i);
		k--;
	}
	return sum;
}


//Teacher 
int T_Recursive_Function_x(int n){
	if ( n == 0 || n == 1 ) return 1;
	long s=0;
	for (int i=0; i <n; i++){
		s += (n-i)*T_Recursive_Function_x(i);
	}
	return s;
}



int Calculate_and_find_x(int x[], int n){ //Calculate sum of n-1 elements of array x
	int sum =0, k = n;
	for (int i=0; i < n; i++){
		sum += k*x[i];
		k--;
	}
	return sum;
}
int Save_the_value_of_x_to_array(int x[], int n){
	for (int i=2; i <= n; i++){
		x[i] = Calculate_and_find_x(x,i);
	}
	return x[n];
}

int main(){
	int n; cout <<"Enter n: "; cin >> n;	
	cout <<"a) x7 = " << Recursive_Function_x(n) << endl;
	cout <<"b) Recursive: " << Recursive_Function_x(n) << endl;
	cout <<"b) Recursive: " << T_Recursive_Function_x(n) << endl;
	int x[10000]; 
	x[0] = 1, x[1] = 1;
	cout <<"c) De-decursion: " << Save_the_value_of_x_to_array(x,n) << endl;
	return 0;
}