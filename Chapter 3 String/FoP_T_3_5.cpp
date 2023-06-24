#include<iostream>
#include<cstring>
#include<windows.h>
using namespace std;
char *input(char *&s){
    s = new char [256];
    fflush(stdin);
    cout <<"Enter string: ";
    cin.getline(s, 256);
    return s;
}

void Problem_a(char *s){
    int count_char = 0, max = 0, global_count = 0;
    for(int i=0; i < strlen(s); i++){
        if( isspace( s[i]) ){
            if ( count_char > max){
                max = count_char;
                global_count = 1;
            }
            else if (count_char == max)
                global_count++;
            
            count_char = 0;           
        }
        
        else
            count_char++;
    }

    if ( count_char > max){
        max = count_char;
        global_count = 1;
    }

    else if (count_char == max)
        global_count++;
    cout << "Từ loại " << max << " được lặp lại " << global_count <<" lần.";
}

void Problem_a_NewVersion(char *s, int a[]){
    
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    char *s ;
    input(s);
    Problem_a(s);

    return 0;
}//Code được làm bởi THug88 =)) 