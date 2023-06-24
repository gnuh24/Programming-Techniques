#include<iostream>
#include<windows.h>
using namespace std;
 void nhap (int *&a, int &n) {
    cout << " nhap so phan tu: ";
    cin >> n;
    a = new int [n];
    for(int i=0;i<n;i++){
        cin >> *(a+i);
    }
}
void xuat(int *a, int n ){
    for(int i=0;i<n;i++){
        cout << *(a+i); 
    }
}
int main(){
   
    int *a,n;
    nhap(a,n);
    xuat(a,n);
    return 0;
}