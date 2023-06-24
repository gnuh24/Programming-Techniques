#include<iostream>
#include<windows.h>
using namespace std;
struct NODE{
    int data;
    NODE* next;
};

struct list{
    NODE* head, * tail;
};

NODE* getnode(int x){
    NODE* p = new NODE;
    if (p == NULL)
        exit(1);
    p -> data = x;
    p -> next = NULL;
    return p;
}

void insert_tail(list &l, NODE* p){
    if ( l.head == NULL)
        l.head = l.tail = p;
    
    else{
        l.tail ->next = p;
        l.tail = p;
    }
}

void create_list(list &l){
    int n, x; cout << "enter n = "; cin >> n;
    for(int i=1; i <= n; i++){
        printf("Enter x[%d] = ", i); cin >> x;
        insert_tail(l, getnode(x) );
    } 
}

void output(list l){
    NODE* p = l.head;
    while( p != NULL){
        cout << p -> data <<" ";
        p = p ->next;
    }
    cout << endl;
}

void create_newlist(list l, list &odd, list &even){
    NODE* p = l.head;
    while(p != NULL){
        if (p -> data % 2 == 0){
            insert_tail(even, getnode(p->data) );
        }
        else
            insert_tail(odd, getnode(p->data) );
        p = p -> next;
    }
}

list best_list_ever;
list odd_number;
list even_number;
int main(){
    SetConsoleOutputCP(CP_UTF8);
    create_list(best_list_ever);
    output(best_list_ever);

    create_newlist(best_list_ever, odd_number, even_number);
    output(odd_number);
    output(even_number);
        output(best_list_ever);

    return 0;
}