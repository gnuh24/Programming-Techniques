#include<iostream>
#include<windows.h>
using namespace std;

void algorithms1(int a[], int n, int m){
    cout << m << endl;
    int count = 0;
    for(int i=0; i < n; i++){
        for(int j = i +1; j < n; j++){
            if ( a[i] + a[j] == m){
                cout << a[i] <<" " <<a[j] << endl;
                count++;
            }
        }
    }
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    int n = 10, m = 10;
    int a[n] = {3, 5, 10, 1, 2, 4, 6, 9 ,7, 12};

    algorithms1(a, n, m);
    return 0;
}