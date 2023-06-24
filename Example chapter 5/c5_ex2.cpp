#include<iostream>
using namespace std;
void output(int a[], int n){
    for(int i=0; i < n; i++){
        cout << a[i] <<" ";
    }
    cout << endl;
}

void algorithms1(int a[], int n, int k){
    int temp;
    for(int i=0; i <k; i++){
        temp = a[0];
        for(int j = 0; j < n-1 ; j++){
            a[j] = a[j+1];
        }
        a[n-1] = temp;
    }
}

void swap(int &a, int &b){
    a = a + b;
    b = a - b;
    a = a - b;
}
void reverse_array(int a[], int u, int v){
    while ( u < v){
        swap( a[u++], a[v--]);
    }
}

void algorithms2(int a[], int n, int k){
    reverse_array(a, 0, k -1);
    reverse_array(a, k, n-1);
    reverse_array(a, 0, n-1);
}

int main(){
    int n = 9;
    int a[n] = {3, 6, 5, 1, 2, 7, 6, 9, 8};
    output(a, n);
    //algorithms1(a,n,3);
    algorithms2(a, n, 3);
    output(a, n);
    return 0;
}