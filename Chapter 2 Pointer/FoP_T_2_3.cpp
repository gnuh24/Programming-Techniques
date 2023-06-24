#include<iostream>
#include<windows.h>
#include<math.h>
using namespace std;
struct monomial
{
    int exponential;
    double coefficient;
};

void create_polynomial(monomial *&polynomial, int &n);
void output(monomial *polynomial, int n);
double find_value_of_polynomial_at_x0(monomial *polynomial, int n, int x);


int main(){
    SetConsoleOutputCP(CP_UTF8);
    monomial *polynomial;
    int n,x;
    create_polynomial(polynomial,n);
    output(polynomial,n);
    cout <<"\n Enter x: "; cin >> x;
    cout << find_value_of_polynomial_at_x0(polynomial,n,x);

    delete polynomial;
    return 0;
}

void create_polynomial(monomial *&polynomial, int &n){
    cout << "Enter n = "; cin >> n;
    polynomial = new monomial[n];
    for (int i=0; i < n; i++){
        cin >> (polynomial+i) -> exponential;
        cin >> (polynomial+i) -> coefficient;
    }
}

void output(monomial *polynomial, int n){
    for (int i=0; i < n; i++){
        printf( " %lfx^%d  ", (polynomial+i) -> coefficient,  (polynomial+i) -> exponential);
        if (i != n-1) cout << "+";
    }
}

double find_value_of_polynomial_at_x0(monomial *polynomial, int n, int x){
    double sum = 0;
    for (int i=0; i < n; i++){
        sum += ( (polynomial+i) -> coefficient ) * pow(x, (polynomial+i) -> exponential );
    }
    return sum;
}