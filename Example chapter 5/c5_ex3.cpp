#include<iostream>

using namespace std;

int max(int a, int b){
    return a > b?a :b;
}

int algorithms1(int a[], int n){
    int max = 0;
    for(int i = 0; i < n -2; i++)
        for(int j = i + 1; j < n- 1; j++)
            for(int k = j +1; k < n; k++)
                if ( a[i]*a[j]*a[k] > max)
                    max = a[i]*a[j]*a[k];  
    return max;
}

void QuickSort(int a[], int left, int right){
    int i, j, x;
    if (left >= right)
        return;
    x =  a[(left + right) / 2];
    i = left; j = right;
    do{
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j){
            swap( a[i], a[j]);
            i++; j--;
        }
    } while (i < j);
    if ( left < j) QuickSort(a, left, j);
    if ( right > i) QuickSort(a, i, right);

}

int algorithms2(int a[], int n){
    int P = a[n-1]*a[n-2]*a[n-3];
    int Q = a[0]*a[1]*a[n-1];
    return P > Q? P:Q;
}

int main(){
    int n =9;
    int a[n] = {5, 7, 8, 9, -9, 6, -8, -3, 5};
    cout <<"a) " << algorithms1(a, n) << endl;
    QuickSort(a, 0, n-1);
    cout <<"b) " << algorithms2(a, n) << endl;
    return 0;
}