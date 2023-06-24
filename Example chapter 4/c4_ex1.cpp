#include <iostream> 
#include<cstring>
using namespace std;
void Tinh(FILE* f,char *s, char *h);
int main()
{
    char *s = new char [256];
    char *h = new char [256];
    strcpy(s, "num.inp");
    strcpy(h, "num.out");

    FILE* f; 
    Tinh(f,s, h);
    delete [] s,h ;
    return 0;
}

void Tinh(FILE* f, char *s, char *h){ 
    f  = fopen(s, "r");
    int sum = 0, n;
    for(int i = 0; i < 3; i++){
        fscanf(f, "%d", &n);
        sum += n;
    }
    fclose(f);
    f = fopen(h, "w");
    fprintf(f,"%d \t", sum);
    //float avg = ;
    fprintf(f, "%f", sum/3.0);
    fclose(f);
}
