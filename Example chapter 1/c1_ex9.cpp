#include<iostream>
using namespace std;
void input(int a[], int &n){
	cout <<"Enter n: "; cin >> n;
	for (int i=0; i < n; i++){
		cout <<"Enter a[" << i <<"]: "; cin >> a[i];
	}
}
int cau_a(int a[], int n, int x){
    if (n == 0) return 0;
    if (a[n-1] == x) return 1 + cau_a(a,n-1,x);
    else return cau_a(a,n-1,x);
}
 
void cau_b(int a[], int n, int x){
    int i = 0,  count = 0;
    for (int i; i < n; i++){
        if ( a[i] == x) {
            cout << i << endl;
            count++;
        }
    }
    if ( count == 0 ) cout << -1;
}


int main(){
    int n, a[10000];
    input(a,n);
    cout << cau_a(a,n,6) << endl;
    cau_b(a,n,3);
    return 0;
}