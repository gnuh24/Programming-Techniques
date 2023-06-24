#include<iostream>
#include<cstring>
#include<windows.h>
using namespace std;
void readFile(FILE*f, char *s, int *&a, int &n){
    f = fopen(s, "r");
    fscanf(f, "%d", &n);
    cout << "n = " << n << endl;
    a = new int [n];
    for(int i = 0; i < n; i++){
        fscanf(f, "%d", a+i);
    }
    fclose(f);
}

void output(int a[], int n){
    for(int i=0; i < n; i++){
        cout << a[i] <<" ";
    }
    cout << endl;
}

/*
Algorithms 1: Vét cạn mãi đỉnh ^^
    + Chỉ đếm số lượng số có tính chất G 
    NOTE!! Algorithms complexity = O(n^3)   
*/
int algorithms1(int *a, int n){
    int count = 0; bool flag;
    for(int i=0; i < n; i++){
        flag = false;
        for(int j = 0; j < n-1 && flag == false; j++){
            if (j == i)
                continue;
            for(int k = j+1; k < n && flag == false; k++){
                if ( k == i)
                    continue;
                if (2 * a[i] == a[j] + a[k]){
                    count++;
                    flag = true;
                }
                    
            }
        }
    }
    return count;
}

/*
Algorithms 2: Vét cạn mãi đỉnh ^^
    + Đếm số lượng cặp G
    + Cho biết các cặp đó là số mấy
    NOTE!! Algorithms complexity = O(n^3)   
*/
struct G
{
    int index_i;
    int index_j;
    int index_k;
};

void algorithms2(FILE*f, G *&listG, int *a, int n){
    int count = 0; 
    bool flag;
    for(int i=0; i < n; i++){
        flag = false;
        for(int j = 0; j < n-1 && flag == false; j++){
            if (j == i)
                continue;
            for(int k = j+1; k < n && flag == false; k++){
                if ( k == i)
                    continue;
                printf("a[%d] = %d, a[%d] = %d, a[%d] = %d \n", i, a[i], j, a[j], k, a[k]);
                if (2 * a[i] == a[j] + a[k]){
                    (listG + count) -> index_i = i ;
                    (listG + count) -> index_j = j ;
                    (listG + count) -> index_k = k ;
                    count++;
                    flag = true;
                }
                    
            }
        }
    }
    fprintf(f, "b) Có %d số có tính G lần lượt là: \n", count);
    for(int i=0; i < count; i++){
        fprintf(f, "a[%d] = %d, %d %d \n", (listG + i) -> index_i ,a[ (listG + i) -> index_i ], a[ (listG + i) -> index_j ], a[ (listG + i) -> index_k ]);
    }
}


int main(){
    SetConsoleOutputCP(CP_UTF8);
    FILE* f; int n, *a;
    char *s = new char [256]; strcpy(s, "c5_5_2.inp");
    char *h = new char [256]; strcpy(h, "c5_5_2.out");
    readFile(f, s, a, n);
    output(a, n);

    f = fopen(h, "w");
    fprintf(f, "a) Số lượng số G trong mảng: %d \n", algorithms1(a, n) );
    G *listG = new G [ algorithms1(a, n) ];
    algorithms2(f, listG, a, n);
    fclose(f);
    delete [] a, s, h, listG;
    return 0;
}