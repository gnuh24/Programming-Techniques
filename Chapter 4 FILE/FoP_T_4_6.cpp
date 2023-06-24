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

void create_array_a(FILE* f, char *s, int *&a, int &m, int &n){
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
int min(int *a, int i, int n){
    int min = INT_MAX;
    for(int j=0; j<n; j++){
        if (min > *(a+ (i*n + j) ) ){
            min = *(a+ (i*n + j) );
        }
    }
    return min;
}
void create_array_b(int *a, int* &b, int m, int n){
    b = new int [m*n];
    for(int i=0; i < m; i++){
        int min_a_i = min(a,i,n);
        for(int j=0; j<n; j++){
            *(b+ (i*n + j)) = *(a+ (i*n+j) ) * min_a_i;
        }
    }
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

void Problem_a(FILE *f, int *b, int m, int n){
    int sum=0;
    for(int i=0; i < m*n; i++){
        sum += *(b+i);
    }
    fprintf(f, "a) Tổng các phần tử trong mảng b: %d\n", sum);
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
int theNearestPrimeNumber(int x){
    if ( isPrime( x ) )
        return x;
    if (x < 2)
        return 2;
    int after = x+1, before = x-1;
    while (!isPrime(after))
        after++;
    while (!isPrime(before))
        before--;
    if (x - before == after - x)
        return before;
    else if(x - before > after - x)
        return after;
    else 
        return before;
    
}
void Prime_maxtrix(int *a, int m, int n){
    for(int i=0; i<m*n; i++){
        *(a+i) = theNearestPrimeNumber( *(a+i) );
    }
}

void Problem_b(FILE*f, int *a, int m, int n){
    int sum=0;
    for(int i=0; i < m*n; i++){
        sum += *(a+i);
    }
    fprintf(f, "b) Tổng các phần tử trong mảng a: %d\n", sum);
}
int max_row(int *a, int i, int n){
    int max = INT_MIN;
    for(int j=0; j<n ;j++){
        if (max < *(a+ (i*n + j))){
            max = *(a+ (i*n + j));
        }
    }
    return max;
}

int min_column(int *a, int m, int n, int j){
    int min = INT_MAX;
    for(int i=0; i <m; i++){
        if (min > *(a+ (i*n + j))){
            min = *(a+ (i*n + j));
        }
    }
    return min;
}
void Problem_c(FILE*f, int *a, int m, int n){
    int saddle_point, saddle_point_rox, saddle_point_column;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if ( min_column(a,m,n,j) == max_row(a,i,n)){
                saddle_point = *(a+ (i*n + j));
                saddle_point_column = j + 1;
                saddle_point_rox = i + 1;
            }
        }
    }
    fprintf(f, "c) Điểm yên ngựa (%d, %d) có giá trị là %d", saddle_point_rox, saddle_point_column, saddle_point);
}
int main(){
    SetConsoleOutputCP(CP_UTF8);
    FILE* f;
    char *s = new char [256]; strcpy(s, "table.inp2");
    char *h = new char [256]; strcpy(h, "table.out2");
    //create_file(f, s);
    int m, n, *a, *b;
    create_array_a(f, s, a, m, n);
    output(a, m, n);
    
    create_array_b(a,b,m,n);
    output(b, m, n);

    Prime_maxtrix(a, m, n);
    output(a, m, n);

    Prime_maxtrix(b, m, n);
    output(b, m, n);
    f = fopen(h, "w");
    Problem_a(f,b,m,n);
    Problem_b(f,a,m,n);
    Problem_c(f,a,m,n);


    fclose(f);
    delete [] s,h,a, b;
    return 0;
}

/*
Author's information
IG: @gnuh.24
FB: Tuấn Hưng
*/ 