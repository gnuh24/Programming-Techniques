#include<iostream>
#include<windows.h>
#include<math.h>

using namespace std;

int Problem_a(int n);
int Problem_b(int n);
void Binery_number(int n);
long long Problem_d(int n);
double Problem_f(int n);

int main(){
    SetConsoleOutputCP(CP_UTF8);
    int n; cout <<"Enter n: "; cin >> n;
    cout << Problem_a(n) << endl;
    cout << Problem_b(n) << endl;
    Binery_number(n); cout << endl;// << endl;
    cout << Problem_d(n) << endl;
    cout << Problem_f(n) << endl;

    return 0;
}

int Problem_a(int n){
    if (n == 0) return 0;
    return n%10 + Problem_a(n/10);
}

int Problem_b(int n){
    if (n == 1) return 1;
    return n + Problem_b(n-1);
}

void  Binery_number(int n){
    if (n > 0){
        Binery_number(n/2);
        cout << n%2;
    }
}

long long Problem_d(int n){
    if (n == 0) return 0;
    return (n % 2 + 10 * Problem_d(n/2));
}

double Problem_f(int n){
    if (n == 1) return sqrt(2);
    return sqrt(2 + Problem_f(n-1));
}