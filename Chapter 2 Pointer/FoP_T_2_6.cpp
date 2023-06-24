#include<iostream>
#include<windows.h>
using namespace std;
struct NODE{
    int data;
    NODE* next;
};

struct list{
    NODE* head, *tail;
};

NODE* getnode(int x){
    NODE* p = new NODE;
    if (p == NULL) exit(1);
    p -> data = x;
    p -> next = NULL;
    return p;
}

void insert_head(list &l, NODE* p){
    if (l.head == NULL) {
        l.head = l.tail = p;
    }
    else{      
        p->next = l.head;
        l.head = p;
    }
}

void insert_tail(list &l, NODE* p){
    if (l.head == NULL) {
        l.head = l.tail = p;
    }
    else{      
        l.tail->next = p;
        l.tail = p;
    }
}

void insert(list l, NODE*p, NODE*q){
    p->next = q->next;
    q->next = p; 
}

void create_list(list &l){
    int n; cout <<"Enter n = "; cin >>n;
    int x;
    for(int i=1; i <= n; i++){
        printf("Enter x[%d] = ", i); cin >> x;
        insert_tail(l, getnode(x) );
    }
}

void output(list l){
    NODE*p = l.head;
    while (p != NULL){
        cout << p->data <<" ";
        p = p->next;
    }
    cout << endl;
}

bool find_x(list l, int x){
    NODE* p = l.head;
    while(p != NULL ){
        if (p -> data == x) return true;
        p = p -> next;
    }
    return false;
}
void delete_head(list &l){
    l.head = l.head -> next;
}

void delete_tail(list &l){
    NODE* p = l.head;
    while (p -> next != l.tail){
        p = p->next;
    }
    l.tail = p;
    p -> next = NULL;
}

void delete_node(list &l, NODE* target){
    if (target == l.head){ //Nếu target ở vị trí đầu
        delete_head(l);
    }
    
    else if (target == l.tail){ //Nếu target ở vị trí cuối
        delete_tail(l);
    }

    else{ //Các vị trí còn lại
        NODE*p = l.head;
        while ( p != NULL){
            if (p -> next == target){
                p -> next = target -> next; 
            }
            p = p -> next;
        }
    }  
}

void SelectionSort(list &l, list& newlist){
    NODE *p; NODE* min;
    while( l.head != NULL){
        p = l.head;
        min = p;
        while(p != NULL){
            if(min -> data > p -> data){
                min = p;
            }
            p = p -> next;
        }
        delete_node(l, min);
        insert_tail(newlist, min);
        
    }
}
list best_list_ever;
list best_list_ever_after_sort;
using namespace std;
int main(){
    SetConsoleOutputCP(CP_UTF8);
    create_list(best_list_ever);
    output(best_list_ever);

    //delete_tail(best_list_ever);
    //output(best_list_ever);
    //cout << find_x(best_list_ever, 3) << endl;

    SelectionSort(best_list_ever, best_list_ever_after_sort);
    output(best_list_ever_after_sort);

    
    return 0;
}