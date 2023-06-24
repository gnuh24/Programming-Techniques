/*
Author's information
IG: @gnuh.24
FB: Tuấn Hưng
*/ 
#include<iostream>
#include<windows.h>
#include<cstring>
#include<math.h>
#include<cstdlib>
#include<ctime>
using namespace std;
void create_file(FILE* f, char *s){
    f = fopen(s, "w");
    srand(time(NULL));
    int m = rand() %10;
    int n = rand() %20;
    fprintf(f, "%d ", m);
    fprintf(f, "%d\n", n);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            fprintf(f, "%d ", rand()%100);
            if (j == n -1)
                fprintf(f, "\n");
        }
    }
    fclose(f);
}

void create_array(FILE* f, char *s, int *&a, int &m, int &n){
    f = fopen(s, "r");
    fscanf(f, "%d", &m);
    fscanf(f, "%d", &n);
    a = new int [m*n];
    for(int i=0; i <m; i++){
        for(int j=0; j<n; j++){
            fscanf(f, "%d", a+(i*n+j));
        }
    }
    fclose(f);
}

void output(int *a, int m, int n){
    for(int i=0; i <m; i++){
        for(int j=0; j<n; j++){
            cout <<*( a+(i*n+j) ) <<" ";
        }
        cout << endl;
    }
    cout << endl;
}

void Problem_a(FILE*f, int *a, int m, int n){
    int max = INT_MIN, count = 1;
    for(int i=0; i <m; i++){
        for(int j=0; j<n; j++){
            if ( max < *(a+ i*n + j)){
                max =   *(a+ i*n + j);
                count = 1;
            }
            else if (max == *(a+ i*n + j))
                count++;                 
        }   
    }
    fprintf(f, "a) Giá trị lớn nhất trong mảng và số lượng: %d %d\n", max, count);
}

void Problem_b(FILE* f, int *a, int m, int n){
    int sum;
    fprintf(f, "b) Tổng các phần tử từng cột: ");
    for(int i=0; i <n; i++){
        sum = 0;
        for(int j=0; j<m; j++){
            sum += *(a + (j*n + i)) ;
        } 
        fprintf(f, "%d ", sum);
    }
    fprintf(f, "\n");
}

bool isPrime(int n){
    if (n < 2)
        return 0;
    int k = sqrt(n);
    for(int i=2; i <= k ; i++){
        if (n % i == 0)
            return 0;
    }
    return 1;
}

bool isPrime_sqare(int *a, int n, int i, int j){
    if ( !isPrime( *(a+ ( i  *n +j))))
        return false;
    if ( !isPrime( *(a+ (i*n +j+1))) )
        return false;

    if ( !isPrime( *(a+ ( (i+1) *n +j))) )
        return false;
    if ( !isPrime( *(a+ ( (i+1) *n + j + 1))))
        return false;
    return true;
}

int SumOfSqare(int *a, int n, int i, int j){
    return *(a+ ( i  *n +j)) + *(a+ (i*n +j+1)) + *(a+ ( (i+1) *n +j)) + *(a+ ( (i+1) *n + j + 1));
}

void Problem_c(FILE* f, int *a, int m, int n){
    int sum = 0, max = INT_MIN;
    for(int i=0; i<m-1; i++){
        for(int j=0; j<n-1; j++){
            if ( isPrime_sqare(a,n,i,j) ){
                if ( max < SumOfSqare(a,n,i,j) )
                    max = SumOfSqare(a,n,i,j);
            }
        }
    }
    fprintf(f, "c) Tổng lớn nhất của hình vuông nguyên tố là: %d", max);
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    FILE* f;
    char *s = new char [256]; strcpy(s, "table.inp");
    char *h = new char [256]; strcpy(h, "table.out");
    //create_file(f, s);
    int m, n, *a;
    create_array(f, s, a, m, n);
    output(a, m, n);
    
    f = fopen(h, "w");
    Problem_a(f,a,m,n);
    Problem_b(f,a,m,n);
    Problem_c(f,a,m,n);


    fclose(f);
    delete [] s,h,a;
    return 0;
}



/*
Author's information
IG: @gnuh.24
FB: Tuấn Hưng
*/ 