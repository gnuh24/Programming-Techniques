#include<iostream>
#include<cstring>
using namespace std;

void realFile(FILE *f, char *s, int *&a ,int &n){
    f = fopen(s, "r");
    fscanf(f, "%d", &n);
    a = new int [n];
    for(int i=0; i<n; i++){ 
        fscanf(f, "%d", (a+i) );
    }
    fclose(f);
}

void output(int *a, int n){
    cout << endl << "n = " << n << endl;
    for(int i=0; i < n; i++){
        cout << *(a+i) <<" ";
    }
    cout << endl;
}

//Trong trường hợp n có thể được xem là đếm n phần tử rồi kết thúc.
//Trả về địa chỉ của thằng lớn nhất
int MaxIndex(int *a, int n){ 
    int index_max = 0;
    for(int i=1; i <n; i++){
        if ( *(a + index_max) <= *(a + i) )
            index_max = i ;
    }
    return index_max;
}

//Trả về L[index]
void Find_L_i(int *a, int *l, int n, int index){
    int IndexTarget = index;
    int maxI = MaxIndex(l, index);
    cout << "maxI = " << maxI << endl;
    for(int i = index-1; i >= 0; i--){
        if ( *(a+i) < *(a+index)){
            cout << "L[i]" <<*(l + i) + 1 << endl;
        }
    }

    if (IndexTarget == index)
        cout << 1 << endl;
}

void LIS_Problem(int *a, int *&l, int *&p, int n){
    l = new int [n];
    p = new int [n];
    int maxIndex;
    for(int i=0; i< n-1; i++){
         Find_L_i(a, l, n, i );
        //*(l + i) =;
    }
    //*(l + (n-1)) = 
    Find_L_i(a, l, n, n-1);

    //output(l, n);
}

int main(){
    int n, *a, *l, *p; FILE* f;
    char *s = new char [256]; strcpy(s, "array.inp");
    realFile(f, s, a, n);
    //output(a, n);

    LIS_Problem(a, l, p, n);
    delete [] a, l, p, s;
    return 0;
}