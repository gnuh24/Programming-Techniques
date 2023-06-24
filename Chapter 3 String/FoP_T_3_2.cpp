#include<iostream>
#include<cstring>
using namespace std;
void input(char *&s){
    s = new char [256];
    cout <<"Enter s: ";cin.getline(s, 256);
}

int FoP_T_3_2_a(char *s, char *x){
    if ( strstr(s,x) == NULL ) return -1;
    return strstr(s, x) - s;
}

int FoP_T_3_2_b(char *s, char *x){
    int count =  0;
    char * temp = s;
    while ( (temp = strstr(temp, x)) != NULL){
        count ++ ;
        temp += strlen(x);
    }
    return count;
}
//Code được làm bởi THug88 =)) 

int main(){
    char *s, *x;
    input(s);
    input(x);
    cout << s << endl;
    cout << x << endl;
    cout << FoP_T_3_2_a(s,x) << endl;
    cout <<  FoP_T_3_2_b(s,x) << endl;
    delete s;
    return 0;
}