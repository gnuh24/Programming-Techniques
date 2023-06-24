#include<iostream>
#include<math.h>
#include<windows.h>
using namespace std;
struct NODE {
    int data;
    NODE* next;
};

struct list{
    NODE* head, *tail;
};

NODE* getnode(int x){
    NODE*p = new NODE;
    if (p == NULL) exit(1);
    p -> data = x;
    p -> next = NULL;
    return p;
}

void output(list l){
    NODE* p = l.head;
    while (p != NULL){
        cout << p->data <<" "; 
        p = p->next;
    }
}
void insert_tail(list &l, NODE* p){
    if (l.head == NULL ){
        l.head = l.tail = p;
    }
    else {
        l.tail -> next = p;
        l.tail = p;        
    }
}
void list_tail(list &l){
    int n, x;
    cout << "Enter n = "; cin >> n;
    for (int i=1; i <= n; i++){
        printf("x[%d] = ", i); cin >> x;
        cout << "Hello ";
        insert_tail(l, getnode(x) );
    }
}

bool isPrime(int n){
    if (n < 2) return 0;
    int k = sqrt(n);
    for (int i=2; i <= k; i++){
        if (n % i == 0) return 0;
    }
    return 1;
}
void delete_Prime(list &l){
    NODE* p = l.head, *temp;
    while (p != NULL){
        if ( isPrime(p->data) == true){
            if (p == l.head){
                l.head = p->next;
                p = l.head;
            }

            else if(p == l.tail){
                l.tail = temp;
            }
            else {
                temp -> next = p -> next;
                p = temp -> next;
            }

        }
        else{
            temp = p;
            p = p -> next;
        }
        
    }
}

int Sum(int n){
    int sum = 0;
    while(n > 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void insert(list l, NODE* p, NODE* q){
    p->next = q->next;
    q->next = p;
}

void Insert_All(list &l){
    NODE* p = l.head;
    while (p != NULL){
        if (p == l.tail){
            insert_tail(l, getnode( Sum(p->data) ) );
        }
        else{
            insert(l, getnode( Sum(p->data)), p);
        }
        p = p->next->next;
    }
}

int main(){
    list tail;
    tail.head =NULL;
    tail.tail = NULL;

    
    SetConsoleOutputCP(CP_UTF8);
    list_tail(tail);
    //delete_Prime(tail);
    Insert_All(tail);
    output(tail);
    
    return 0;
}