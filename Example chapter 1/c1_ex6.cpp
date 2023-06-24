#include<iostream>
#include<math.h>
#include<windows.h>
using namespace std;
void input_array(int a[], int &n);
int Problem_a(int a[], int n);
bool Check_Prime(int n);
int Problem_b(int a[], int n);
int Problem_c(int a[], int n, int x, int left_index, int right_index);
int Problem_d(int a[], int n);

int main(){
    SetConsoleOutputCP(CP_UTF8);
    int a[100000],n;
    input_array(a,n);
    cout << "a = " << Problem_a(a,n) << endl;

    cout << "b = " << Problem_b(a,n) << endl;

    cout << "c = " << Problem_c(a,n,3,0,n-1) << endl;

    cout << "d = " << Problem_d(a,n) << endl;
    
    return 0;
}
void input_array(int a[], int &n){
    cout <<"Enter n: "; cin >> n;
    for (int i = 0; i < n; i++){
        cout << "a["<< i <<"] = "; cin >> a[i];
    }
}

bool Check_Prime(int n){
    if (n < 2) return false;
    int k = sqrt(n);
    for (int i=2; i <= k; i++){
        if (n % i ==0) return false;
    }
    return true;
}
int Problem_a(int a[], int n){
    if (n == 1) return a[0] ;  
    if ( a[n-1] > Problem_a(a,n-1) ) return a[n-1];
    else return Problem_a(a,n-1);
}

int Problem_b(int a[], int n){
    if (n == 1) return Check_Prime(a[0]);
    return Check_Prime(a[n-1]) + Problem_b(a,n-1);
}

int Problem_c(int a[], int n, int x, int left_index, int right_index){
    if (left_index <= right_index){
        int mid = (left_index + right_index) / 2;
        if (a[mid] == x) return mid;
        else if (a[mid] > x){
            return Problem_c(a,n,x,left_index, mid - 1);
        }
        //else if (a[mid] < x){}
        return Problem_c(a,n,x,mid + 1, right_index);
        
    }
    return -1;
}
int Problem_d(int a[], int n){
    if (n == 1) return a[0];
    return a[n-1] + Problem_d(a,n-1);
}