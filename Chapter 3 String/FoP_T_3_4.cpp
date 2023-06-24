#include<iostream>
#include<cstring>
#include<windows.h>
using namespace std;

void input(char *&s, char *&x, char *&y ){
    s = new char[255];
    x = new char[255];
    y = new char[255];
        cout <<"Enter s: "; cin.getline(s, 255);  
        cout <<"Enter x: "; cin.getline(x, 255); 
        cout <<"Enter y: "; cin.getline(y, 255);   
}

//Chuỗi s thay thế các chuỗi con x bằng chuỗi con y
char *changed(char *s, char *x, char *y){
    if (strstr(s,x) == NULL){
        return NULL;
    }
    while( strstr(s,x) != NULL){
        char *temp = new char [256];
        strcpy(temp, strstr(s,x) + strlen(x)); 
        strcpy(s + (strstr(s,x) - s), y );
        strcat(s, temp);
    }
    return s;
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    char *s, *x, *y;
    input(s,x,y);
    cout << changed(s,x,y);
    delete s, x, y;
    return 0;
}//Code được làm bởi THug88 =)) 