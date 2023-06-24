#include<iostream>
#include<cstring>
using namespace std;
struct FRACTION
{
    int tu;
    int mau;
};

void input(FILE *f, char *s, FRACTION *phanso, int n){
    f = fopen(s, "wb");
    putw(n, f);
    for(int i=0; i < n; i++){
        printf("Tu[%d] = ", i); cin >> (phanso + i) -> tu;
        printf("Mau[%d] = ", i); cin >> (phanso + i) -> mau;
    }
    fwrite(phanso, sizeof(FRACTION), n, f);
    fclose(f);

}

void output(FILE *f, char *s, int n){
    f = fopen(s, "rb");
    FRACTION *ps = new FRACTION[n];
    int k = getw(f);
    cout << k << endl;
    fread(ps, sizeof(FRACTION), k, f);

    for(int i=0; i < k; i++){
        cout<< (ps+i) -> tu <<"/"<< (ps+i) -> mau << endl;
    }
    fclose(f);

}

int main(){
    FILE *f;
    int n; cout <<"Enter n: "; cin >> n;
    FRACTION *phanso = new FRACTION[n];
    char *s = new char [256]; strcpy(s, "phanso.txt");
    input(f, s, phanso, n);
    output(f, s,  n);

    delete [] phanso, s;
    return 0;
}
