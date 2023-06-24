#include<iostream>
using namespace std;
void input(int *&a, int &m, int &n);
void output(int *a, int m, int n);
int count_x(int *a, int m, int n, int x);
void Find_index_x(int *a, int m, int n, int x);
int main(){
    int *a, m, n; 
    input(a,m,n);
    output(a,m,n);
    cout << count_x(a,m,n,3) << endl;
    Find_index_x(a,m,n,3);
    return 0;
}
void input(int *&a, int &m, int &n)
{
	cout<<"Enter m : ";cin>>m;
	cout<<"Enter n : ";cin>>n;
	//a = new int [m*n];
	for(int i=0;i<m;i++){
	    for(int j=0;j<n;j++){
            cin>>*(a+i*n+j);
        }
    }
}
void output(int *a, int m, int n)
{
	for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
             cout<<*(a+i*n+j)<<" ";
        }  
        cout<<endl;
	}
}
int count_x(int *a, int m, int n, int x){
    int count = 0;
    for (int i=0; i < m; i++){
        for (int j=0; j < n; j++){
            if ( x == *(a+n*i+j)) count++;
        }
    }
    return count;
}
void Find_index_x(int *a, int m, int n, int x){
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (x == *(a+n*i+j)) {
                printf("a[%d][%d] \n", i,j );
            }
        }
    }
}