#include<iostream>
#include<windows.h>
using namespace std;
void input(int a[], int &n){   
    cout << "Enter n: "; cin >> n;
    for (int i=1; i <= n; i++){
        cout <<"a[" <<i <<"] = "; cin >> a[i];
    }
}
void output(int a[], int n){
    for (int i=1; i <= n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}
void Heap_Sort(int a[], int n){
    
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    int a[10000], n;
    input(a,n);
    output(a,n);
    Heap_Sort(a,n);
    output(a,n);
    return 0;
}