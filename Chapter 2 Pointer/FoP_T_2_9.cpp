#include<iostream>
#include<windows.h>
#include<math.h>
using namespace std;

struct NODE
{
    int data;
    NODE* left, *right;  
};

void getnode(NODE* &root, int x){
    if (root != NULL){
        if(root -> data < x) 
            return getnode(root -> right, x);
        else 
            return getnode(root -> left, x);
    }
    else{
        root = new NODE;
        if (root == NULL )
            cout<< "Error";
        root -> data = x;
        root -> left = root -> right = NULL;
    }
}


void create_tree(NODE* &root){
    int n, x; cout <<"Enter n = "; cin >> n;
    for(int i = 1; i <= n; i++){
        printf(" x[%d] = ", i); cin >> x;
        getnode(root,x); 
    }
}

void LNR(NODE* root){
    if (root != NULL){
        LNR(root -> left);
        cout << root -> data << " ";
        LNR(root -> right);
    }
}

bool isPrime(int n){
    if (n < 2) return false;
    int k = sqrt(n);
    for(int i= 2; i <= k ; i ++)
        if (n % i == 0) 
            return false;
    return true;
}

int count_prime(NODE* root){
    if (root != NULL) {
        if ( isPrime(root->data))
            return 1 + count_prime(root -> left) + count_prime(root -> right);
        else 
            return 0 + count_prime(root -> left) + count_prime(root -> right);
    }
    return 0;
}   

NODE* find_x_ver1(NODE* root, int x) {
    if (root == NULL || root->data == x) {
        return root;
    }
    if (x > root->data) {
        return find_x_ver1(root->right, x);
    }
    return find_x_ver1(root->left, x);
}

bool find_x_ver2(NODE* root, int x){
    if (root == NULL) return 0;
    if (root -> data == x) return 1;
    return find_x_ver2(root -> left, x) + find_x_ver2(root -> right, x); 
}

void find_x_ver3(NODE* root, int x){
    if (root == NULL ) return;
    cout << root -> data << " ";
    if ( root -> data == x) return;
    if ( root -> data < x) {
        find_x_ver3(root -> right, x); 
    }
    else
        find_x_ver3(root -> left, x);
}

int Tim_muc(NODE* root, int x){
    if (root == NULL ) return 0;
    if ( root -> data == x) return 1;
    if ( root -> data < x) {
        return 1 + Tim_muc(root -> right, x); 
    }
    else
        return 1 + Tim_muc(root -> left, x);
}

int Height_of_tree(NODE* root) {
    if (root == NULL) return 0;
    int a = Height_of_tree(root -> left);
    int b = Height_of_tree(root -> right);
    if ( a > b)
        return a+1;
    return b+1;
}

int main(){
    NODE* tree = NULL;
    create_tree(tree);
    LNR(tree); cout << endl;
    cout << "a) Number of prime number on the binary tree = " << count_prime(tree) << endl;
    cout << "b) "<< find_x_ver1(tree, 6) -> data << endl;
    cout << "b) "<< find_x_ver2(tree, 6)  << endl;
    cout << "c) "; find_x_ver3(tree, 6); cout << endl;
    cout << "d) " << Tim_muc(tree, 19) << endl;
    cout << "e) Height of tree = " << Height_of_tree(tree) << endl;
    return 0;
}

