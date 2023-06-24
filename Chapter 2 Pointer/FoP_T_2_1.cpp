/*
2.1 Cho mảng 1 chiều chứa n số nguyên dương
a) Nhập k, xóa phần tử tại vị trí k
b) Nhập x, k, chèn x vào vị trí k
c) Xóa toàn bộ số ngto khỏi mảng
*/

#include <iostream>
#include <math.h>
using namespace std;

void input(int *&a, int &n);
void output(int *a, int n);
// a) Nhập k, xóa phần tử tại vị trí k
void delete_element(int *a, int &n, int k);

// b) Nhập x, k, chèn x vào vị trí k
void insert(int *a, int &n, int x, int k);

// c) Xóa toàn bộ số ngto khỏi mảng
bool Check_Prime(int n);
void delete_prime(int *a, int &n);

int main()
{
    int *a, n;
    input(a, n);
    int k; // cout << "Enter k = "; cin >> k;
    // delete_element(a,n,k);
    output(a,n);
    
    
    
    //insert(a, n, x, k);
    //output(a, n);
    
    delete_prime(a,n);
    output(a,n);
    delete a;
    return 0;
}

void input(int *&a, int &n)
{
    cout << "Enter n = ";
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        cin >> *(a + i);
    }
}

void output(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = %d \n", i, *(a + i));
    }
}

void delete_element(int *a, int &n, int k)
{ // Con trỏ A không thay đổi
    for (int i = k; i < n - 1; i++)
    {
        *(a + i) = *(a + (i + 1));
    }
    n--;
}

void insert(int *a, int &n, int x, int k)
{
    n++;
    for (int i = n - 1; i >= k; i--)
    {
        if (i == k)
            *(a + i) = x;
        else
            *(a + i) = *(a + (i - 1));
    }
}

bool Check_Prime(int n)
{
    if (n < 2)
        return 0;
    int k = sqrt(n);
    for (int i = 2; i <= k; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void delete_prime(int *a, int &n)
{
    int i = 0;
    do
    {
        if (Check_Prime(*(a + i)) == true)
        {
            delete_element(a, n, i);
        }
        if (Check_Prime(*(a + i)) == false)
            i++;
    } while (i < n);
}
