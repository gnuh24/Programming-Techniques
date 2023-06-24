//Add library
#include<iostream>
#include<cstring>
#include<math.h>
#include<windows.h>
using namespace std;

void create_list(FILE* f, char *s , int *&a, int &m, int &n){
    f = fopen(s, "r");
    fscanf(f, "%d", &m);
    fscanf(f, "%d", &n);
    a = new int[m*n];
    int x;
    for(int i=0; i < m; i++){
        for(int j = 0; j < n; j++){
            fscanf(f, "%d", &x);
            *(a+ (i*n + j) ) = x;
        }
        
    }
    fclose(f);
}

void output(int *a, int m, int n){
    for(int i=0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << *(a+ (i*n +j) ) <<" ";
        }
        cout << endl;
    }
}

void Problem_a(FILE* f, int *a, int m, int n){
    int sum = 0;
    for(int i=0; i < m; i++){
        for(int j = 0; j < n; j++){
            sum += *(a+ (i*n +j) ) ;
        }
    }
    fprintf(f, "a) Tổng các phần tử: %d\n", sum);
}

bool isPrime(int n){
    if (n  < 2)
        return 0;
    int k = sqrt(n);
    for(int i=2; i <= k; i++){
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void Problem_b(FILE*f,  int *a, int m, int n){
    int count = 0;
    for(int i=0; i < m; i++){
        for(int j = 0; j < n; j++){
            if ( isPrime( *(a+ (i*n +j) ) ) )
                count++;
        }
    }
    fprintf(f, "b) Số lượng số nguyên tố: %d\n", count);

}

void Problem_c(FILE*f, int *a, int m, int n){
    int sum;
    fprintf(f, "c) Tổng các phần tử trên mỗi dòng: ");
    for(int i=0; i < m; i++){
        sum = 0;
        for(int j = 0; j < n; j++){
            sum += *(a + (i*n + j) );
        }
        fprintf(f, "%d ", sum);
    }
}

void Problem_d(FILE*f, int *a, int m, int n){
    int sum;
    fprintf(f, "\nd) Tổng các phần tử trên mỗi cột: ");
    for(int i=0; i < n; i++){
        sum = 0;
        for(int j = 0; j < m; j++){
            sum += *(a + (j*n + i) );
        }
        fprintf(f, "%d ", sum);
    }
}

void Problem_e(FILE*f,  int *a, int m, int n){
    int even = 0, odd = 0;
    fprintf(f, "\ne) Số lượng số chẵn, số lẽ: " );
    for(int i=0; i < m; i++){
        for(int j = 0; j < n; j++){
            if ( *(a + ( i*n + j) ) %2 == 0)
                even++;
            else
                odd++;
        }
    }
    fprintf(f, "%d %d", even, odd );

}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    int m, n;
    int *a;
    FILE* f;
    char *s = new char [256], *h = new char [256];
    strcpy(s, "table.inp");
    strcpy(h, "table.out");

    create_list(f, s, a, m ,n);
    output(a, m, n);

    f = fopen(h, "w");
    Problem_a(f, a, m, n);
    Problem_b(f, a, m, n);
    Problem_c(f, a, m, n);
    Problem_d(f, a, m, n);
    Problem_e(f, a, m, n);

    fclose(f);
    delete []s, h, a;
    return 0;
}

