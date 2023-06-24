#include <iostream>
#include <math.h>
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

NODE *getnode(int x)
{
    NODE *p = new NODE;
    if (p == NULL)
        exit(1);
    p->data = x;
    p->next = NULL;
    return p;
}

void insert_head(list &l, NODE *p)
{
    if (l.head == NULL)
    {
        l.head = p;
        l.tail = p;
    }
    else
    {
        p->next = l.head;
        l.head = p;
    }
}

void list_insert_head(list &l)
{
    int x, n;
    cout << "Enter n = ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        printf("Enter x%d = ", i);
        cin >> x;
        insert_head(l, getnode(x));
    }
}

void insert_tail(list &l, NODE *p)
{
    if (l.head == NULL)
    {
        l.head = p;
        l.tail = p;
    }
    else
    {
        l.tail->next = p;
        l.tail = p;
    }
}

void list_insert_tail(list &l)
{
    int x, n;
    cout << "Enter n = ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        printf("Enter x%d = ", i);
        cin >> x;
        insert_tail(l, getnode(x));
    }
}

void output(list l)
{
    NODE *p = l.head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

NODE *Find_x(list l, int x)
{
    NODE *p = l.head;
    while (p != NULL)
    {
        if (p->data == x)
        {
            return p;
        }
        else
        {
            p = p->next;
        }
    }
    return NULL;
}

void insert_after_node_q(list &l, NODE *q, int x)
{

    NODE *p = getnode(x);
    if (p == NULL)
        exit(1);
    if (q != NULL)
    {
        p->next = q->next;
        q->next = p;
        if (q == l.tail)
            l.tail = p;
    }
    else
    {
        insert_head(l, p);
    }
}

bool find_x_2(list l, int x)
{
    NODE *p = l.head;
    while (p != NULL)
    {
        if (p->data == x)
            return 1;
        else
            p = p->next;
    }
    return 0;
}
void swap(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}
void InterchangeSort(list &l)
{
    for (NODE *p = l.head; p != l.tail; p = p->next)
        for (NODE *q = p->next; q != NULL; q = q->next)
            if (p->data > q->data)
                swap(p->data, q->data);
}

void SelectionSort(list &l)
{
    for (NODE *p = l.head; p != l.tail; p = p->next)
    {
        NODE *min = p;
        for (NODE *q = p->next; q != NULL; q = q->next)
        {
            if (q->data < min->data)
            {
                min = q;
            }
        }
        swap(min->data, p->data);
    }
}

int Tong(list l)
{
    NODE *p = l.head;
    int sum = 0;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

void Noi(list &l1, list l2)
{ // Nối list 2 vào cuối list 1
    l1.tail->next = l2.head;
    l1.tail = l2.tail;
}

int Tong_dau_cuoi(list l)
{
    return l.head->data + l.tail->data;
}

int Tong_3_ptr(list l)
{
    NODE *p = l.head;
    int sum = 0;
    for (int i = 1; i <= 3; i++)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

void delete_1st_element(list &l)
{
    l.head = l.head->next;
}

list head;

list tail;
int main()
{
    SetConsoleOutputCP(CP_UTF8);

    // list_insert_head(head);
    // output(head);

    list_insert_tail(tail);
    output(tail);
    delete_1st_element(tail);
    output(tail);
    // cout << Tong_dau_cuoi(tail) << endl;
    // cout << Tong_3_ptr(tail) << endl;

    // Noi(head, tail);
    // output(head);
    // InterchangeSort(tail);
    // SelectionSort(tail);
    // cout << find_x_2(tail,2);
    // insert_after_node_q(tail,Find_x(tail,3),4);
    // output(tail);
    return 0;
}