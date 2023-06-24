/*
Author's information
IG: @gnuh.24
FB: Tuấn Hưng
*/ 
#include<iostream>
#include<cstring>
#include<windows.h>
#include<math.h>
using namespace std;

struct FRACTION{
    int numerator; //Tử số
    int denominator; //Mẫu số
};

void read_file(FILE *f, char *s, FRACTION phanso[], int &serial){
    f = fopen(s, "r");
    while ( !feof(f) ){
        fscanf(f, "%d", &serial);
        fscanf(f, "%d", &phanso[serial].numerator);
        fscanf(f, "%d", &phanso[serial].denominator);
    }
    serial++;
    fclose(f);
}

//a) Đếm xem có bao nhiêu phân số nhỏ hơn 1
void Problem_a(FILE*f, FRACTION phanso[], int serial){
    int count = 0;
    for(int i=0; i < serial; i++){
        if ( phanso[i].numerator < phanso[i].denominator){
            count++;
        }            
    }
    fprintf(f, "a) Số lượng phân số nhỏ hơn 1: %d\n", count);   
}

//b) Đếm xem có bao nhiêu phân số tử chia hết cho mẫu
void Problem_b(FILE*f, FRACTION phanso[], int serial){
    int count = 0;
    for(int i=0; i < serial; i++){
        if ( phanso[i].numerator % phanso[i].denominator == 0)
            count++;
    }
    fprintf(f, "b) Số lượng phân số có tử chia hết cho mẫu là: %d\n", count);   
}

//c) Đếm xem có bao nhiêu phân số mà tử và mẫu đều là số nguyên tố
bool isPrime(int n){
    if (n < 2)
        return 0;
    int k = sqrt(n);
    for(int i=2; i <= k; i++)
        if (n % i == 0)
            return 0;
    return 1;
}
void Problem_c(FILE*f, FRACTION phanso[], int serial){
    int count = 0;
    for(int i=0; i < serial; i++)
        if ( isPrime( phanso[i].numerator ) == true && isPrime( phanso[i].denominator ) == true)
            count++;
    fprintf(f, "c) Số lượng phân số có tử và mẫu đều là số nguyên tố: %d\n", count);   
}

//d) Tìm phân số có giá trị lớn nhất
void Problem_d(FILE*f, FRACTION phanso[], int serial){
    FRACTION max = phanso[0];
    for(int i=1; i < serial; i++)
        if (  (1.0 * phanso[i].numerator / phanso[i].denominator) >  (1.0 * max.numerator / max.denominator))
            max = phanso[i];
          
    fprintf(f, "d) Phân số lớn nhất là: %d/%d\n", max.numerator, max.denominator);   
}

void Problem_e(FILE*f, FRACTION phanso[], int serial){
    FRACTION max_u1, min_1;
    max_u1.numerator = 0;
    max_u1.denominator = INT_MAX ;
    min_1.numerator = INT_MAX;
    min_1.denominator = 0.01 ;
    
    //Find the biggest fraction what smaller than 1
    for(int i=0; i < serial; i++)
        if (  (1.0 * phanso[i].numerator / phanso[i].denominator) >  (1.0 * max_u1.numerator / max_u1.denominator) && phanso[i].numerator < phanso[i].denominator)
            max_u1 = phanso[i];
          
    //Find the smallest fraction what bigger than 1
    for(int i=0; i < serial; i++)
        if (  (1.0 * phanso[i].numerator / phanso[i].denominator) <  (1.0 * min_1.numerator / min_1.denominator) && phanso[i].numerator > phanso[i].denominator)
            min_1 = phanso[i];
    

    fprintf(f, "e) Phân số lớn nhất nhỏ hơn 1 là: %d/%d\n", max_u1.numerator,  max_u1.denominator);   
    fprintf(f, "   Phân số nhỏ nhất lớn hơn 1 là: %d/%d\n", min_1.numerator,  min_1.denominator);   
}

//f) Đếm xem có bao nhiêu phân số tối giản
int gcd(int a, int b){
    int r = a % b;
    while ( r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}
void Problem_f(FILE*f, FRACTION phanso[], int serial){
    int count = 0;
    for(int i=0; i < serial; i++)
        if ( gcd(phanso[i].numerator, phanso[i].denominator) == 1)
            count++;
    fprintf(f, "f) Số lượng phân số tối giản: %d\n", count);   
}

//g) Giá trị trung bình cộng giữa các phân số
void Problem_g(FILE*f, FRACTION phanso[], int serial){
    float sum = 0;
    for(int i=0; i < serial; i++)
        sum += (1.0*phanso[i].numerator / phanso[i].denominator);
    fprintf(f, "g) Trung bình cộng của các phân số: %f\n", sum/(serial));   
}


int main(){
    SetConsoleOutputCP(CP_UTF8);
    FILE*f; 
    FRACTION phanso[100];
    int serial;
    char *s = new char [256]; strcpy(s, "fraction.inp");
    char *h = new char [256]; strcpy(h, "fraction.out");
    read_file(f, s, phanso, serial);
    f = fopen(h, "w");
    Problem_a(f, phanso, serial);   //a) Đếm xem có bao nhiêu phân số nhỏ hơn 1
    Problem_b(f, phanso, serial);   //b) Đếm xem có bao nhiêu phân số tử chia hết cho mẫu
    Problem_c(f, phanso, serial);   //c) Đếm xem có bao nhiêu phân số mà tử và mẫu đều là số nguyên tố
    Problem_d(f, phanso, serial);   //d) Tìm phân số có giá trị lớn nhất
    Problem_e(f, phanso, serial);   //e) Tìm phân số nhỏ hơn 1 lớn nhất và lớn hơn 1 nhỏ nhất
    Problem_f(f, phanso, serial);   //f) Đếm xem có bao nhiêu phân số tối giản
    Problem_g(f, phanso, serial);   //g) Giá trị trung bình cộng giữa các phân số
    fclose(f);
    delete [] s, h;
    return 0;
}
/*
Author's information
IG: @gnuh.24
FB: Tuấn Hưng
*/ 