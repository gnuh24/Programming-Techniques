#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;



void input(char *&s){
    s = new char[256];
    cout <<"Enter s = "; cin.getline(s, 256);
}

void count_upper_lower(char *s){
    int upper =0, lower =0;
    for(int i=0; i < strlen(s); i++){
        if ( isupper(s[i]) ) upper++;
        if ( islower(s[i]) ) lower++;
    }
    cout << "a) Upper: " << upper << endl;
    cout << "   Lower: " << lower << endl;
}

void find_ascii(char *s){
    cout << "b) Ascii: ";
    for(int i=0; i < strlen(s); i++){
        cout << int(s[i]) << " ";
    }
    cout << endl;
}

void upper_lower(char *s){
    strlwr(s);
    s[0] = toupper(s[0]);
    for(int i=1; i< strlen(s); i++){
        if ( isspace( s[i]) ) s[i+1] = toupper(s[i+1]);
    }
    cout <<  "c) "<< s << endl;
}

int count_word(char *s){
    int count = 0;
    for(int i=0; i < strlen(s); i++){
        if ( isspace(s[i])) count++;
    }
    return count + 1;
}

void count_number_char_of_word(char *s){
    int count = 0;
    cout << "d) ";
    for(int i=0; i < strlen(s); i++){
        count++;
        if ( isspace(s[i]) ) {
            cout << count-1 << " ";
            count = 0;
        }
        if ( i == strlen(s) - 1){
            cout << count << " ";
        }
    }
}

char* left(char *s){
    return strtok(s," ");
}

char* right(char *s){
    strrev(s);
    return strrev( strtok(s," ") );
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    char *s;
    input(s);
    cout << s << endl;
    count_upper_lower(s);
    find_ascii(s);
    upper_lower(s);
    cout << "d) " << count_word(s) << endl;
    count_number_char_of_word(s);
    //cout <<"e) Left: " << left(s) << endl;
    cout <<"   Right: " << right(s) << endl;

    delete s;
}


//Code được làm bởi THug88 =)) 