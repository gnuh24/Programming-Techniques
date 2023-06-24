#include<iostream>
#include<cstring>
#include<windows.h>
using namespace std;

void real_file(FILE*f, char *s, int &start, int a[][100], int &n){
    f = fopen(s, "r");
    fscanf(f, "%d %d", &start, &n);
    for(int i=0; i < n; i ++){
        for(int j=0; j < n ; j++){
            fscanf(f, "%d", &a[i][j]);
        }
    }
    fclose(f);
}
void output2(int a[][100], int n){
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            cout << a[i][j] <<" ";
        }
        cout << endl;
    }
    cout << endl;
}

void output(int a[], int n){
    for(int i=1; i <= n; i++){
            cout << a[i] <<" ";       
    }
    cout << endl;
}

void output_map(int a[], int n){
    for(int i=0; i <= n; i++){
            cout << a[i] <<" ";       
    }
    cout << endl;
}

void TaoMangCoPhanTuToanKhong(int a[], int n){
    for(int i=1; i  <= n; i ++){
        a[i] = 0;
    }
    cout << "Khởi tạo thành công bản đồ đường đi. " << endl;
}

bool Check(int a[], int n){
    bool flag = true;
    for(int i=1; i <= n && flag == true; i ++){
        if ( a[i] == 0 )
            flag = false;
    }
    return flag;
}

int IndexcurrentMin(int DuongDi[], int n, int a[][100], int start){
    int index_min; bool find = 0;
    for(int i=1; i <=n && find == 0; i++){  
        if ( DuongDi[i] != 1 && a[start-1][i-1] != 0){
            index_min = i-1;
            find = 1;
        }
    }
    for(int i = 1; i  <= n ; i++){
        if ( a[start-1][i-1] != 0 && DuongDi[i] == 0 && a[start-1][i-1] < a[start-1][index_min] ){
            index_min =  i-1;
        }
    }
    return index_min;
}

void  TSP1_myAlgorithms(int a[][100], int start, int n){
    int cost = 0;
    bool flag = false;
    int next;
    int temp = start;
    int ThanhPhoDaDi[n+1]; 
    TaoMangCoPhanTuToanKhong(ThanhPhoDaDi, n);
    while (flag == false){        
        //B1: Đánh dấu vị trí hiện tại 
        ThanhPhoDaDi[start] = 1;
        cout << start << " -> " ; 
        //B2: Tìm đường đi tiếp theo (Nếu đã đi hết rồi thì quay lại thành phố ban đầu)
        if (Check(ThanhPhoDaDi, n))
            next = temp-1;
        else
            next = IndexcurrentMin(ThanhPhoDaDi, n , a, start);    
        
        //B3: Tính chi phí cộng tiền lại 
        cost += a[start-1][next] ;

        //B4:  Lưu lại đường đi tiếp theo (Check gg map)    
        start = next+1;     
        //B5: Xem coi mình có nên đi tiếp không
        flag = Check(ThanhPhoDaDi, n); 
        
    }
    cout << temp << endl;
    cout << "Tổng chi phí tối thiểu: " << cost << endl;
}

int TSP1(int a[][100], int map[],int start, int n){
    int cost = 0;
    bool flag = false;
    int next;
    int cur = 0;
    int temp = start;
    int ThanhPhoDaDi[n+1]; 
    TaoMangCoPhanTuToanKhong(ThanhPhoDaDi, n);
    while (flag == false){        
        //B1: Đánh dấu vị trí hiện tại 
        ThanhPhoDaDi[start] = 1;
        map[cur++] = start;
        //B2: Tìm đường đi tiếp theo (Nếu đã đi hết rồi thì quay lại thành phố ban đầu)
        if (Check(ThanhPhoDaDi, n))
            next = temp-1;
        else
            next = IndexcurrentMin(ThanhPhoDaDi, n , a, start);    
        
        //B3: Tính chi phí cộng tiền lại 
        cost += a[start-1][next] ;

        //B4:  Lưu lại đường đi tiếp theo (Check gg map)    
        start = next+1;     
        //B5: Xem coi mình có nên đi tiếp không
        flag = Check(ThanhPhoDaDi, n); 
        
    }
    map[cur++] = start;
    return cost;
}

void TSP2(int a[][100], int n){
    int map[n+1];
    int temp_map[n+1];
    int smallest_cost = INT_MAX;
    for(int i=1; i<=n; i++){
        int temp = TSP1(a, temp_map, i, n);
        if ( temp < smallest_cost ){
            smallest_cost = temp;
            for(int j=0; j <= n; j++){
                map[j] = temp_map[j];
            }
        }
    }
    cout << "Bản đồ đường đi ngắn nhất: " << endl;
    output_map(map, n);
    cout << "Chi phí: " << smallest_cost << endl;
}


int main(){
    SetConsoleOutputCP(CP_UTF8);
    int n, start, a[100][100];
    FILE *f; 
    char s[256]; strcpy(s, "matrix.inp");
    real_file(f,s,start,a,n);
    cout << "Start = " << start << endl;
    output2(a, n);
    TSP1_myAlgorithms(a, start, n);
    //TSP2(a, n);
    return 0;
}