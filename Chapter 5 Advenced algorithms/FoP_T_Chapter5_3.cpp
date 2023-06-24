#include<iostream>
#include<windows.h>
#include<ctime>
using namespace std;
int sumOfDivisor(int n){ // O(n)
    int sum = 0;
    for(int i=1; i < n; i++){
        if (n % i == 0)
            sum += i;
    }
    return sum;
}

//Thuật toán 1: p cố định, q thuộc(1, 10 ^ 6)
int algorithms1(int p){ // O(n^2)
    int count = 0;
    for(int i=2; i < 100000; i++){
        if ( sumOfDivisor(p) == sumOfDivisor(i) )
            count++;
    }
    return count;
}

//Update thuật toán 1: In ra cặp số p, q
void algorithms2(int p){ // O(n^2)
    int count = 0;
    for(int i=2; i < 1000000; i++){
        if ( sumOfDivisor(p) == i && p == sumOfDivisor(i) ){
            count++;
            cout << p << " " << i << endl;
        }
    }
    cout << count << endl;
}

//Thuật toán 3: Quét từ 1 tới 1 000 000 xem có bao nhiều cặp
void algorithms3(){ // O(n^2)
    int count = 0;
    for(int p=2; p < 1000000; p++){
        for(int q = 2; q < 1000000; q++){
            if (q == p)
                continue;
            if ( sumOfDivisor(p) == q && p == sumOfDivisor(q) ){
                    count++;
                    cout << p << " " << q << endl;
                }
        }
    }
    cout << count << endl;
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    //int p; cout << "p = "; cin >> p;
    
    clock_t begin = clock();
    //cout << algorithms1(p) << endl;
    algorithms3();
    clock_t end = clock();
    cout << double(end - begin) / CLOCKS_PER_SEC;
    return 0;
}