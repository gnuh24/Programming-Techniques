#include<iostream>
using namespace std;
struct NODE{
    int data;
    NODE* left;
    NODE* right;
};

void getnode(NODE* &roof, int x){
    if (roof != NULL){
        if (roof -> data < x) return getnode(roof->right, x);
        else return getnode(roof -> left, x);
    }
    else{
        roof = new NODE;
        if (roof == NULL) 
            cout << -1;
        roof -> data = x;
        roof -> left = roof -> right = NULL;
    }
}

void create(NODE* &roof){
    int n, x; cout <<"Enter n = "; cin >> n;
    for(int i = 1; i <= n; i++){
        printf("x[%d] = ", i ); cin >> x;
        getnode(roof, x);
    }
}

void LRN(NODE* roof){
    if( roof != NULL){
        LRN(roof -> left);
        LRN(roof -> right);
        cout << roof -> data << " ";
    }
}

void LNR(NODE* roof){
    if (roof != NULL){
        LNR(roof -> left);
        cout << roof -> data <<" ";
        LNR(roof -> right);
    }
}

void NLR(NODE* roof){
    if (roof != NULL){
        
        cout << roof -> data <<" ";
        NLR(roof -> left);       
        NLR(roof -> right);
    }
}

int main(){
    NODE* tree = NULL;
    create(tree);
    NLR(tree);
    LNR(tree);
    LRN(tree);
    return 0;
}