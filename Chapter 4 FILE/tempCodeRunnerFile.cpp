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
    fprintf(f, "%d ", n);
    int m; cout <<"Enter m: "; cin>> m;
    fprintf(f, "%d\n", m);
    for(int i=0; i <=n; i++){
        fprintf(f, "%d ", rand()%100);
    }
    
    fclose(f);
}


void create_array(FILE* f, char*s, int *&a, int &n, int &m){
    f = fopen(s, "r");
    fscanf(f, "%d", &n);
    fscanf(f, "%d", &m);
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
    int max = *a;
    for(int i=1; i <n; i++){
        if (*(a+i) > max)
            max = *(a+i);
    }
    fprintf(f, "a) Giá trị lớn nhất trong dãy: %d\n", max);
}

void Problem_b(FILE* f, int *a, int n){
    int length = 1, maxLen = 0, start_index=0; 
    
    for(int i=0; i <n-1; i++){
        if ( *(a+i) <= *(a+i+1))
            length++;
        else{
            if (length > maxLen){
                maxLen = length;
                start_index = i - maxLen;
            }
            length = 1;
        }
    }

    if (length > maxLen){
        maxLen = n;
        start_index = n - maxLen;
    }

    fprintf(f, "b) Chiều dài dãy con liên tiếp tăng dài nhất: %d - ", maxLen);
    for(int i = start_index; i < start_index + maxLen; i++){
        fprintf(f, "%d ", *(a+i));
    }
    fprintf(f, "\n");
}

struct point{
    int x;
    int y;
};

void delete_point(point diem[], int &count, int index){
    for(int i=index; i < count - 1 ;i++){
        diem[i] = diem[i+1];
    }
    count--;
}

void Problem_c(FILE*f, int *a, int n, int m){
    int count=0; 
    //Đếm số lượng các cặp tổng = m
    for(int i=0; i < n; i++){
        for(int j = 0; j<n; j++){
            if (i == j)
                continue;
            else{
                if ( *(a+i) + *(a+j) == m ){      
                    count++;
                }
            }
        }
    }


    //Cho số liệu vào mảng point
    point D[count];
    int count2 = 0;
    cout << count << endl;
    for(int i=0; i < n; i++){
        for(int j = 0; j<n; j++){
            if (i == j)
                continue;
            else{
                if ( *(a+i) + *(a+j) == m ){      
                    D[count2].x = *(a+i);
                    D[count2++].y = *(a+j);
                }
            }
        }
    }
    //Lọc các phần tử không đúng yêu cầu
    for(int i=0; i < count-1; i++){
        for(int j=i+1; j<n; j++){
            if ( D[i].x == D[j].y && D[i].y == D[j].x){
                delete_point(D, count, j);
                j--;
            }
        }
    }
    fprintf(f, "c) Số lượng các cặp có tổng = m: %d\n", count);
}

void swap(int &a, int &b){
    a = a + b;
    b = a - b;
    a = a - b;
}

void SeletionSort(int *a, int n){
    int index;
    for(int i=0; i < n-1; i++){
        int index = i;
        for(int j= i + 1; j<n; j++){
            if (*(a+j) < *(a+index))
                index = j;
        }
        if (index != i)
            swap(*(a+i), *(a+ index));
    }
}
void Problem_d(FILE* f, int *a, int n){
    fprintf(f, "d) Giá trị ở vị trí trung vị của mảng là: %d", *(a + (n / 2) ) );
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    FILE* f;
    int n, *a, m;
    char *s = new char [256]; 
    char *h = new char [256];

    strcpy(s, "NUM.INP");
    strcpy(h, "NUM.OUT");

    //create_file(f, s);
    create_array(f, s, a, n, m);
    output(a,n);
    
    f = fopen(h, "w");
    //Problem_a(f, a, n);
    Problem_b(f, a, n);
    //Problem_c(f, a, n, m);
    //SeletionSort(a, n);
    //output(a, n);
    //Problem_d(f, a, n);
    fclose(f);

    delete [] s, h, a;
    return 0;
}

/*
Author's information
IG: @gnuh.24
FB: Tuấn Hưng
*/ 