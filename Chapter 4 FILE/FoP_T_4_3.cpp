/*
Author's information
IG: @gnuh.24
FB: Tuấn Hưng
*/ 

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<math.h>
#include<windows.h>
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

void Problem_a(FILE* f, int *a, int m, int n){
    int count = 0;
    for(int i=0; i <m; i++){
        for(int j=0; j<n; j++){
            if (  isPrime( *( a+(i*n+j) ) ) )
                count++;
        }
    }
    fprintf(f, "a) Số lượng số nguyên tố trong file là: %d\n", count);
}

void Problem_b(FILE* f, int *a, int m, int n){
    int sum, max = 0;
    for(int i=0; i <m; i++){
        sum = 0;
        for(int j=0; j<n; j++){
            sum += *( a+(i*n+j) ) ;            
        }
        if (max < sum)
            max = sum;
    }
    fprintf(f, "b) Tổng lớn nhất của mỗi dòng là: %d\n", max);
}

void Problem_c(FILE* f, int *a, int m, int n){
    int sum, min = INT_MAX;
    for(int i=0; i <n; i++){
        sum = 0;
        for(int j=0; j<m; j++){
            sum += *( a+(j*n+i) ) ;            
        }
        if (min > sum)
            min = sum;
    }
    fprintf(f, "c) Tổng lớn nhất của mỗi cột là: %d\n", min);
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
    delete [] s, h, a;
    return 0;
}

/*
Author's information
IG: @gnuh.24
FB: Tuấn Hưng
*/ 