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
    int max = INT_MIN, min;
    for(int i=0; i <m; i++){
        min = *(a+ (i*n) );
        for(int j=0; j<n; j++){
            if (min > *(a+(i*n + j))){
                min = *(a+(i*n + j));
            }          
        }   
        if (max < min)
            max = min;
    }
    fprintf(f, "a) Giá trị lớn nhất trong các giá trị nhỏ nhất của mỗi dòng: %d \n", max);
}

void Problem_b(FILE* f ,int *a, int m, int n){
    int min = INT_MAX, index_x1, index_x2, index_y1, index_y2;
    for (int i=0; i <m; i++){
        for(int j=0; j<n; j++){
            int val1 = *(a+ (i*n+ j ));
            for(int k=0; k<m ;k++){
                for(int p=0; p<n ;p++){
                    if ( i == k && j == p)
                        continue;
                    int val2 = *(a+ (k*n + p) );
                    int dis = abs(val2 - val1);
                    if ( min > dis){
                        min = dis;
                        index_x1 = i;
                        index_y1 = j;
                        index_x2 = k;
                        index_y2 = p;
                    }
                }
            }
        }
    }
    fprintf(f, "b) Giá trị và vị trí của 2 nơi nhỏ nhất là: %d %d %d %d %d", min, index_x1+1, index_y1+1, index_x2+1, index_y2+1);
}


int main(){
    SetConsoleOutputCP(CP_UTF8);
    FILE* f;
    char *s = new char [256]; strcpy(s, "table.inp2");
    char *h = new char [256]; strcpy(h, "table.out2");
    //create_file(f, s);
    int m, n, *a;
    create_array(f, s, a, m, n);
    output(a, m, n);
    
    f = fopen(h, "w");
    Problem_a(f,a,m,n);
    Problem_b(f,a,m,n);


    fclose(f);
    delete [] s,h,a;
    return 0;
}



/*
Author's information
IG: @gnuh.24
FB: Tuấn Hưng
*/ 