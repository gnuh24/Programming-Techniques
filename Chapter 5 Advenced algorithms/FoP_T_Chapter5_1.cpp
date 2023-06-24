#include<iostream>
#include<windows.h>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void QuickSort(int a[], int left, int right){
    int i, j, x;
    if (left >= right)
        return;
    x =  a[(left + right) / 2];
    i = left; j = right;
    do{
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j){
            swap( a[i], a[j]);
            i++; j--;
        }
    } while (i < j);
    if ( left < j) QuickSort(a, left, j);
    if ( right > i) QuickSort(a, i, right);

}
void output(int a[], int n){
    for(int i=0; i < n; i++){
        cout << a[i] <<" ";
    }
    cout << endl;
}

//Số lượng giá trị khác nhau trong mảng
int Problem_a(int a[], int n){
    if (n == 0)
        return 0;
    int count = 1;
    for(int i=0; i < n-1; i++){
        if (a[i] != a[i+1]){
            count++;
        }
    }
    return count;
}


/*b)
Đặt vấn đề mới (Không có trong đề cương): 
- In ra màn hình số lượng giá trị khác nhau trong mảng và in tất cả các giá trị đôi 1 khác nhau đó ra (
    NOTE!! : 
    +   Được dùng mảng phụ 
    +    QuickSort
    +   Không được dùng câu a
*/
int Problem_b(int a[], int b[], int n, int &count_b){
    if (n == 0)
        return count_b;

    b[count_b++] = a[0];
    
    for(int i=0; i < n-1; i++){
        if ( a[i] != a[i+1] ){
            b[count_b++] = a[i+1] ;
        }
    }
    return count_b;
}

/*c)
Đặt vấn đề mới (Không có trong đề cương): 
- In ra màn hình số lượng giá trị khác nhau trong mảng và in tất cả các giá trị đôi 1 khác nhau đó ra (
    NOTE!! : 
    +   KHÔNG Được dùng mảng phụ 
    +   QuickSort
    +   Không được dùng câu a
*/
void Problem_c(int a[], int n){
    int count = 1; cout << a[0] <<" " ;
    for(int i=0; i < n-1; i++){
        if ( a[i] != a[i+1] ){
            cout << a[i+1] << " ";
            count++;
        }
    }
    cout << "length: " << count << endl;
}

/*d)
Đặt vấn đề mới (Không có trong đề cương): 
- In ra màn hình số lượng giá trị khác nhau trong mảng và in tất cả các giá trị đôi 1 khác nhau đó ra (
    NOTE!! : 
    +   Không được dùng mảng phụ 
    +   NO QuickSort
    +   Không được dùng câu a
*/
void Problem_d(int a[], int n){
    int count = 1; cout << a[0] <<" " ;
    for(int i=0; i < n; i++){
        if (i >= 1){
            bool flag = true;
            for(int j = 0; j < i && flag == true; j++){
                if (a[j] == a[i]){
                    flag = false;
                }
            }
            if (flag == true){
                count++;
                cout << a[i] <<" ";
            }

        }
    }
    cout << "length: " << count << endl;
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    int n = 12;
    int a[1000] = {8, 6, 3, 3, 9, 6, 17, 9, 6, 3, 100, 18};
    output(a, n);
    QuickSort(a, 0, n-1);
    output(a, n);

    cout << "a) Số lượng giác trị khác nhau trong mảng là: "<< Problem_a(a, n) << endl; 
    // a) QUickSort + Problem_a = O( max(nlogn, n) ) =O(n)

    int b[10000]; int count_b = 0;
    cout << "b) " << Problem_b(a, b, n, count_b) << endl;
    output(b, count_b);
    // b) QUickSort + Problem_b = O( max(nlogn, n) ) =O(n)

    Problem_c(a, n);

    int d[1000] = {8, 6, 3, 3, 9, 6, 17, 9, 6, 3, 100, 18};
    Problem_d(d, n);


    return 0;
}