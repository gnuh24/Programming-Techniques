/*
Author's information
IG: @gnuh.24
FB: Tuấn Hưng
*/ 
#include<iostream>
#include<cstring>
#include<math.h>
#include<cstdlib>
#include<ctime>
#include<windows.h>

using namespace std;

bool isPrime(int n){
    if (n < 2)
        return 0;
    int k = sqrt(n);
    for(int i = 2; i <= k; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

void create_file(FILE* f, char*s){
    f = fopen(s, "w");
    srand(time(NULL));
    int n = rand() % 11 + 10;
    fprintf(f, "%d\n", n);
    for(int i=0; i <=n; i++){
        fprintf(f, "%d ", rand()%100);
    }
    fclose(f);
}

void create_array(FILE* f, char*s, int *&a, int &n){
    f = fopen(s, "r");
    fscanf(f, "%d", &n);
    int x;
    a = new int [n];
    for(int i=0; i< n; i++){
        fscanf(f, "%d", &x);
        *(a+i) = x;
    }
    fclose(f);
}

void output(int *a, int n){
    for(int i=0; i< n; i++)
        cout << *(a+i) <<" ";
    cout << endl;
}

void Problem_a(FILE* f, int *a, int n){
    int count = 0;
    for(int i=0; i < n; i++){
        if ( isPrime(*(a+i) ) )
            count++;
    }
    fprintf(f, "a) Số lượng số nguyên tố: %d\n", count);
}

void swap(int &a, int &b){
    a = a + b;
    b = a - b;
    a = a - b;
}

void Problem_b(FILE* f, int *a, int n){
    for(int i=0; i < n-1; i++){
        for(int j = n - 1; j > i; j--){
            if ( *(a+j) < *(a+i))
                swap(*(a+j), *(a+i) );
        }
    }
    int x;
    fprintf(f, "b) Bubble sort: ");
    for(int i=0; i < n; i++){
        fprintf(f, "%d ", *(a+i));
    }
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    FILE* f;
    int n, *a;
    char *s = new char [256]; 
    char *h = new char [256];

    strcpy(s, "NUM.INP");
    strcpy(h, "NUM.OUT");

    create_file(f, s);
    create_array(f, s, a, n);
    output(a,n);
    
    f = fopen(h, "w");
    Problem_a(f, a, n);
    Problem_b(f, a, n);
    fclose(f);
    delete [] s, h, a;
    return 0;
}
/*
Author's information
IG: @gnuh.24
FB: Tuấn Hưng
*/ 