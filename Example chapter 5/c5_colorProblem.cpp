#include<iostream>
#include<cstring>
#include<windows.h>
using namespace std;

void real_file(FILE*f, char *s, int a[][100], int &n){
    f = fopen(s, "r");
    fscanf(f, "%d", &n);
    for(int i=0; i <n; i++){
        for(int j=0; j< n; j++){
            fscanf(f, "%d", &a[i][j]);
        }
    }
    fclose(f);
}

void output_matrix_2D(int a[][100], int n){
    cout << "n = " << n << endl;
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            cout << a[i][j] <<" ";
        }
        cout << endl;
    }
}

void output_1D(int a[], int n){
    for(int i=1; i <= n; i++){
        cout << a[i] <<" ";
    }
    cout << endl;
}

void FindDegreeOfVertex(int a[][100], int DegreeOfVertex[], int ListCity[], int n){
    int count;
    for(int i=0; i <n; i++){
        count = 0;
        for(int j=0; j<n; j++){
            if ( a[i][j] == 1){
                count++;
            }
        }
        DegreeOfVertex[i+1] = count;
        ListCity[i+1] = i+1;
    }
}
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

//Hàm QuickSort này sẽ sort giảm dần các phần tử trong mảng mức, và các phần tử trong danh sách luôn
void QuickSort(int Degree[], int List[],int left, int right){
    if (left >= right)
        return;
    int i, j, pilot;
    i = left; j = right;
    pilot = Degree[ (i+j) / 2];

    do
    {
        while ( Degree[i] > pilot) i++;
        while ( Degree[j] < pilot) j--;
        if ( i <= j ){
            swap( Degree[i], Degree[j] );
            swap( List[i++], List[j--] );
        }
    } while (i < j);

    if (i < right) 
        QuickSort(Degree, List, i, right);
    if (left < j)
        QuickSort(Degree, List, left, j);
        
    
}

//Đếm số giá trị khác nhau trong mảng (Đếm số mức có trong bài toán này phục vụ cho việc sắp xếp lần nữa)
int CountNumberOfDegree(int Degree[], int n){
    int count = 1;
    for(int i=1; i <n; i++){
        if ( Degree[i] != Degree[i+1] )
            count++;
    }
    return count; 
}

//Trả về vị trí đầu tiên của giá trị lớn thứ i
int FirstIndex(int Degree[], int n, int serial){
    int i = 1;
    bool flag = false;
    int count = 1;
    if (count == serial)
        flag = true;
    while (flag == false && i < n){
        if ( Degree[i] != Degree[++i] ){
            count++;
            if (count == serial){
                flag = true;
            }
        }
    }
    return i;
}

//Hàm này trả về số lượng phần tử có giá trị thứ i
int RangeOfIndex(int Degree[], int n, int FirstIndex){
    int range =1, i = FirstIndex;
    bool flag = true;
    while (flag == true && i < n){
        if ( Degree[i] == Degree[++i] ){
            range++;
        }
        else{
            flag = false;
        }
    }
    return range;
}

void interchange_sort(int a[], int start, int end){
    for(int i=start; i <end; i++){
        for(int j=i+1; j<=end; j++){
            if (a[i] > a[j])
                swap(a[i], a[j]);
        }
    }
}

//Hàm này dùng để sort thành phố theo thứ tự ưu tiên
void FinalSort(int Degree[], int ListOfCity[], int n){
    int NumberOfTimesToSort = CountNumberOfDegree(Degree, n);
    for(int i=1; i <= NumberOfTimesToSort; i++){
        int j = FirstIndex(Degree, n, i); 
        int k = RangeOfIndex(Degree, n , j); 
        interchange_sort(ListOfCity, j, j+k-1);
    }
}

//Hàm này kiểm tra xem các thành phố đã được tô màu hết hay chưa?
bool Check(int Color[], int n){
    bool flag = true;
    for(int i=1; i <=n && flag == true; i++){
        if ( !Color[i] )
            flag = false;
    }
    return flag;
}

//Hàm này kiểm tra xem còn thành phố nào cùng thuộc tính mà chưa tô màu không
bool  CheckColor(int a[][100], int Color[], int n, int SerialOfCity){
    bool flag = false;
    //List[] = {3,1,2,4,6,5}
    for(int i=1; i <=n && flag == false; i++){
        if ( a[SerialOfCity-1][i-1] == 0 && Color[i] == 0){
            flag = true;    
        }
    }
    return flag;
}
//Hàm này để chuyển các phần tử của mảng về 0
void Zero(int Color[], int n){
    for(int i=1; i<=n; i++){
        Color[i] = 0;
    }
}

//Hàm này dùng để tô màu =)) Giải quyết vấn đề chính của bài toán
void ColorTheCities(int a[][100],int n){
    int DegreeOfVertex[n+1];  //Mảng này chứa bậc của từng thành phố
    int ListOfCity[n+1];  // Mảng này thì chứa danh sách các thành phố, sẽ được sort cùng lúc với mảng DegreeOfVertex
    //Bước 1: Tìm bậc cho các thành phố
    FindDegreeOfVertex(a, DegreeOfVertex, ListOfCity,  n);
    
    //Bước 2: Sắp xếp các bậc theo chiều giảm dần
    QuickSort(DegreeOfVertex, ListOfCity, 1, n);
    /*
    NOTE!! Sort xong sẽ xuất hiện tình trạng các thành phố cùng bậc nhảy loạn xạ =)) 
    Phải sort 1 lần nữa để cho các thành phố có số ít hơn được ưu tiên
    */
    FinalSort(DegreeOfVertex, ListOfCity, n);

    cout << "Degree: "; output_1D(DegreeOfVertex, n);
    cout << "List: "; output_1D(ListOfCity, n);

    int Color[n+1]; Zero(Color, n);
    int SerialOfColor = 1; //Serial của màu
    int FirstTarget = 1; //vị trí mục tiêu cần tô trong ListOfCity
    while ( !Check(Color, n) ){
        cout <<"First target = " << FirstTarget << endl;
        //Tô màu  cho vị trí đầu tiên
        bool flag = 0;
        while (flag == 0){
            if ( Color[ ListOfCity[ FirstTarget ] ] == 0){
                cout <<"Đã tô màu gốc "<< SerialOfColor<< " cho thành phố " <<ListOfCity[ FirstTarget] << endl;
                Color[ ListOfCity[ FirstTarget] ] = SerialOfColor;
                flag = 1;
  
            }
            else
                FirstTarget++;
            
        }
       
        //Tô màu cho các vị trí còn lại
        int SecondTarget = FirstTarget + 1; 
  
        while ( CheckColor(a, Color, n, ListOfCity[FirstTarget] ) == true){

            if ( a[ListOfCity[FirstTarget] - 1][ListOfCity[SecondTarget] - 1] == 0 && Color[ListOfCity[SecondTarget]] == 0 ){
                Color[ListOfCity[SecondTarget]] = SerialOfColor;
                cout <<"Đã tô màu "<< SerialOfColor << " cho thành phố " << ListOfCity[ SecondTarget] << endl;
            }
            SecondTarget++;

        }

        SerialOfColor++;
        FirstTarget++;
    }
    cout <<"Color: ";
    output_1D(Color, n);
}


int main(){
    SetConsoleOutputCP(CP_UTF8);
    FILE*f;
    char s[256]; strcpy(s, "colorCity.inp");
    int a[100][100], n;
    real_file(f, s, a, n);
    //output_matrix_2D(a, n);
    int c[n+1];
    ColorTheCities(a, n);
    return 0;
}

