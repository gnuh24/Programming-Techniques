//Add library
#include<iostream>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<math.h>

using namespace std;

//Tạo file ngẫu nhiên n số
void create_file(FILE *f, char *s, int &n);


int Sum(FILE* f, char *s, int n);
int Max(FILE* f, char *s, int n);

//c) Đếm số nguyên tố
bool isPrime(int n);
int Count_prime(FILE* f, char *s, int n);

//d) Đếm số vừa nguyên tố vừa đối xứng
int reverse_number(int n);
int Problem_d(FILE* f, char* s, int x);

//e) Tổng tất cả các chữ số của các phần tử
int Problem_e(FILE* f, char *s, int n);
int tongCacChuSo(int n);

int main(){
    FILE *f; int n;
    char *s = new char [256];
    strcpy(s, "sequence.inp");
    create_file(f, s, n);
    cout << Sum(f, s, n) << endl;
    cout << Max(f, s, n) << endl;
    cout << Count_prime(f, s, n) << endl;
    cout << Problem_d(f, s, n) << endl;
    cout << "e) Tong cac chu so: " << Problem_e(f, s, n) << endl;

    return 0;
}

void create_file(FILE *f, char *s, int &n){
    f = fopen(s, "wt");
    cout <<"Enter n = "; cin >> n;
    fprintf(f, "%d\n", n);
    srand(time(NULL));
    int x;
    for(int i=1; i <= n; i++){
        fprintf(f, "%d ", rand()%50);
        if (i % 10 == 0)
            fprintf(f, "\n");
    }
    fclose(f);
}

int Sum(FILE* f, char *s, int n){
    int sum = 0, x;
    f = fopen(s, "r");
    fscanf(f, "%d", &x);
    for(int i=1; i <= n; i++){
        fscanf(f, "%d", &x);
        sum += x;
    }

    fclose(f);
    return sum;
}

int Max(FILE* f, char *s, int n){
    f = fopen(s, "r");
    int max, x;
    fscanf(f, "%d", &x);
    fscanf(f, "%d", &max);

    for(int i=1; i <= n; i++){
        fscanf(f, "%d", &x);
        if (max < x)
            max = x;
    }
    return max;
}

bool isPrime(int n){
    if (n < 2)
        return 0;
    int k = sqrt(n);
    for(int i=2; i < n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

int Count_prime(FILE* f, char *s, int n){
    int count = 0, x;
    f = fopen(s, "r");
    fscanf(f, "%d", &x);
    for(int i = 0; i < n ;i++){
        fscanf(f, "%d", &x);
        if ( isPrime(x) )
            count++;
    }
    return count;
}

int reverse_number(int n){
    int newnum = 0;
    while(n != 0){
        newnum = newnum*10 + ( n % 10 );
        n /= 10;
    }
    return newnum;
}

int Problem_d(FILE *f, char *s, int n){
    f = fopen(s, "r");
    int x, count = 0;
    fscanf(f,"%d" ,&x);
    for(int i=1; i <= n; i++){
        fscanf(f, "%d", &x);
        if ( isPrime(x) == true && reverse_number(x) == true)
            count++;
    }
    return count;
}

int tongCacChuSo(int n){
    int sum = 0;
    while (n > 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int Problem_e(FILE* f, char *s, int n){
    int sum = 0, x;
    f = fopen(s, "r");
    fscanf(f, "%d", &x);
    for(int i=1; i <= n; i++){
        fscanf(f, "%d", &x);
        sum += tongCacChuSo(x);
    }
    return sum;
}