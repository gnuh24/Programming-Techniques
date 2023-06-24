// Mẫu
#include <iostream>
#include<math.h>
#include <windows.h>
using namespace std;

struct NODE
{
    int data;
    NODE *next;
};

struct list
{
    NODE *head, *tail;
};

NODE* getnode(int x){
    NODE* p = new NODE;
    if (p == NULL) exit(1);
    p->data = x;
    p->next = NULL;
    return p;
}

void insert_tail(list &l, NODE* p){
    if (l.head == NULL){
        l.head = l.tail = p;
    }
    else{
        l.tail->next = p;
        l.tail = p;
    }
}

void list_insert_tail(list &l){
    int x, n;
    cout << "Enter n = "; cin >> n;
    for (int i=1; i <= n; i++){
        printf("Enter x%d = ", i);
        cin >> x;
        insert_tail(l, getnode(x));
    }
}

void output(list l){
    NODE* p = l.head;
    while (p != NULL){
        cout << p->data <<" ";
        p = p -> next;
    }
}

int Problem_a(list l){
    int sum =0;
    NODE* p = l.head;
    while(p != NULL){
        sum += p->data;
        p = p->next;
    }
    return sum;
}

bool is_prime(int n){
    if (n < 2) return 0;
    int k = sqrt(n);
    for (int i=2; i <= k; i++){
        if (n % i == 0) return 0;
    }
    return 1;
}

int Problem_b_count_prime_number(list l){
    NODE* p = l.head;
    int count =0;
    while (p != NULL){
        if ( is_prime(p -> data) == true ) count++;
        p = p-> next;
    }
    return count;
}

int Problem_c_count_odd_number(list l){
    NODE* p = l.head;
    int count =0;
    while (p != NULL){
        if (p->data % 2 != 0) count++;
        p = p -> next;
    }
    return count;
}

int Problem_c_count_even_number(list l){
    NODE* p = l.head;
    int count =0;
    while (p != NULL){
        if (p->data % 2 == 0) count++;
        p = p -> next;
    }
    return count;
}

int Problem_d_max(list l){
    int max = l.head->data;
    NODE* p = l.head;

    while (p != NULL){
        if (p -> data > max) max = p->data;
        p = p-> next;
    }
    return max;
}

void delede(list &l){
    l.head = l.head -> next;
}

list tail;
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    list_insert_tail(tail);
    output(tail);
    cout << "\na) Tổng các phần tử trong list là " << Problem_a(tail) << endl;
    cout << "b) Số lượng số nguyên tố trong danh sách là: " << Problem_b_count_prime_number(tail) << endl;
    cout << "c) Số lượng số lẽ trong danh sách là: " << Problem_c_count_odd_number(tail) << endl;
    cout << "c) Số lượng số chẵn trong danh sách là: " << Problem_c_count_even_number(tail) << endl;
    cout << "d) Giá trị lớn nhất trong danh sách là: " << Problem_d_max(tail) << endl;
    delede(tail);
    output(tail);
    return 0;
}