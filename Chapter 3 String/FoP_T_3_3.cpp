#include<iostream>
#include<cstring>
using namespace std;
void input(char *&s){
    s = new char [256];
    cout <<"Enter s: ";cin.getline(s, 256);
}

//a) Xoa l ky tu tu vi tri p cua chuoi s
char *Problem_a(char *s, int l, int p){
    strcpy(s+p, s+p+l);
    return s;
}
//Code được làm bởi THug88 =)) 
//b) Chen s2 vao cho q cua s1
char *Problem_b(char *s, char*k, int q){
    char *temp = new char[256];
    strcpy(temp, s+q);
    strcpy(s+q, k);
    strcpy(s + strlen(s), temp);
    return s;
}

int main(){
    char *s, *x;
    input(s);
    input(x);
    //cout <<"a) " << Problem_a(s,9,3) << endl;
    cout <<"b) " << Problem_b(s,x,13) << endl;

    delete s;
    return 0;
}