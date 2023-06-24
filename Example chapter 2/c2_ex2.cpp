#include<iostream>
using namespace std;
void input(int *&a, int &n);
void output(int *a, int n);
int GTLN(int *a,int n);
void swap(int *a, int *b);
void Sort(int *a, int n);
int main(){
    int *a, n;
    input(a,n);
    output(a,n);
	cout << "Max = " << GTLN(a,n);
	Sort(a,n);
    output(a,n);
	delete a;
    return 0;
}
void input(int *&a, int &n){
    cout <<"Enter n = "; cin >> n;
    a = new int[n];
    for (int i=0; i < n; i++){
        printf("Enter a[%d] = ", i); cin >> *(a+i);
    }
}
void output(int *a, int n){
    for (int i=0; i < n ; i ++){
        printf("a[%d] = %d \n", i, *(a+i));
    }
}
int GTLN(int *a,int n)
{
	int max=*a;
	for(int i=0;i<n;i++)
 	if (*(a+i)>max) max=*(a+i);
 	return max;
}
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void Sort(int *a, int n){
    for (int i=0; i < n-1; i++){
        for (int j=i+1; j<n; j++){
            if ( *(a+i) > *(a+j) ) swap(*(a+i), *(a+j));
        }
    }
}
