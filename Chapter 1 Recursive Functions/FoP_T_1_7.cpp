#include<iostream>
#include<math.h>
using namespace std;

void input(int a[], int &n){
	cout <<"Enter n: "; cin >> n;
	for (int i=0; i < n; i++){
		cout <<"Enter a[" << i <<"]: "; cin >> a[i];
	}
}

int Sum_of_elements(int a[], int n){
	if ( n == 1 ) return a[0];
	return a[n-1] + Sum_of_elements(a,n-1);
}

int Max(int a[], int n)
{
	if ( n == 1) 
		return a[0];
	if ( a[n-1] > Max(a,n-1) ) 
		return a[n-1];
	else return 
		Max (a,n-1);
	
}

int Min(int a[], int n){
	if ( n == 1) return a[0];
	if ( a[n-1] < Min(a,n-1)) return a[n-1];
	else return Min(a,n-1);
}

bool isPrime(int n){
	if ( n < 2) return false;
	int k = sqrt(n);
	for (int i=2; i <= k; i++){
		if ( n % i == 0) return false;
	}
	return true;
}

int countPrime(int a[], int n){
	if ( n == 1 ) 
		return isPrime(a[0]);
	return isPrime(a[n-1]) + countPrime(a,n-1);
}

int main(){
	int a[10000], n;
	input(a,n);
	cout <<"a) Sum of elements of array a = " << Sum_of_elements(a,n) << endl;
	cout <<"b) The biggest number in array a = " << Max(a,n) << endl;
	cout <<"   The smallest number in array a = " << Min(a,n) << endl;
	cout <<"c) The number of primes in array a =" << countPrime(a,n) << endl;
	return 0;
}