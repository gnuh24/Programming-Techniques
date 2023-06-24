
#include<iostream>
#include<windows.h>
using namespace std;
void input(int a[], int &n){   
    cout << "Enter n: "; cin >> n;
    for (int i=0; i < n; i++){
        cout <<"a[" <<i <<"] = "; cin >> a[i];
    }
}
void output(int a[], int n){
    for (int i=0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}
void input_b_c(int a[], int b[], int c[], int n){
    int flag = 1, count_b = 0, count_c = 0;
    for (int i=0; i < n-1; i++){
        if ( flag <= 1){
            b[count_b] = a[i];
            count_b = count_b + 1;
        }
        else {
            c[count_c] = a[i];
            count_c = count_c + 1;
        }
        if (a[i] > a[i+1]) flag = -flag;
    }
    cout << endl;
    for (int i=0; i < count_b; i++){
        cout << b[i] << " " ; 
    }
    cout << endl;
    for (int i=0; i < count_c; i++){
        cout << c[i] << " " ; 
    }
}

//void Merge_Sort(int a[], int n){   }

int main(){
    SetConsoleOutputCP(CP_UTF8);
    int a[10000],b[10000], c[10000], n;
    input(a,n);
    output(a,n);
    input_b_c(a,b,c,n);
    //Merge_Sort(a,b,c,n);
    //output(a,n);
    return 0;
}