#include<iostream>
#include<math.h>
using namespace std;

struct NODE{
    int data;
    NODE* left, * right;
};

void getnode(NODE* &root, int x){
    if (root != NULL){
        if(root -> data < x) 
            getnode(root -> right, x);
        else 
            getnode(root -> left, x);
    }
    else{
        root = new NODE;
        if (root == NULL)
            cout<< "The value is not valid";
        root -> data = x;
        root -> left = root -> right = NULL;
    }
}

void create(NODE* &root){
    int n, x; 
    cout <<"Enter n = "; 
    cin >> n;
    for(int i = 1; i <= n; i++){
        printf("x[%d] = ", i ); 
        cin >> x;
        getnode(root, x);
    }
}

void LRN(NODE* root){
    if( root != NULL){
        LRN(root -> left);
        LRN(root -> right);
        cout << root -> data << " ";
    }
}

void LNR(NODE* root){
    if (root != NULL){
        LNR(root -> left);
        cout << root -> data <<" ";
        LNR(root -> right);
    }
}

void NLR(NODE* root){
    if (root != NULL){
        cout << root -> data <<" ";
        NLR(root -> left);       
        NLR(root -> right);
    }
}

void NRL(NODE* root){
    if (root != NULL){
        cout << root -> data <<" ";
        NRL(root ->right);
        NRL(root ->left);
    }
}

void RNL(NODE* root, int k){
    if (root != NULL){
        RNL(root ->right, k);
        if (root -> data > k)
            cout << root -> data <<" ";
        RNL(root ->left, k);
    }
}

void RLN(NODE* root){
    if (root != NULL){
        RLN(root ->right);
        RLN(root ->left);
        cout << root -> data <<" ";
    }
}

int Sum_of_all_elements(NODE* root){
    if (root == NULL) 
        return 0;
    return root -> data + Sum_of_all_elements(root -> left) + Sum_of_all_elements(root -> right);
}

int Max(NODE* root){
    int max;
    while(root != NULL){
        if (root -> right == NULL) {
            max = root -> data;
            break;
        }
        else
            root = root -> right;
    }
    return max;
}

int Number_of_node_of_tree(NODE* root){
    // Code for number of nodes in a tree goes here
    if (root == NULL) return 0;
    return 1 + Number_of_node_of_tree(root -> left) + Number_of_node_of_tree(root -> right);
}

int Number_of_leaf_of_tree(NODE* root){
    if (root -> left == NULL && root -> right == NULL) return 1;
    if (root -> left == NULL) return Number_of_leaf_of_tree(root -> right);
    if (root -> right == NULL) return Number_of_leaf_of_tree(root -> left);
    return Number_of_leaf_of_tree(root -> left) + Number_of_leaf_of_tree(root -> right);
}

int Number_of_node_that_has_1_leaf(NODE* root){
    if (root -> left == NULL && root -> right == NULL) return 0;
    if (root -> left == NULL ) return 1 + Number_of_node_that_has_1_leaf(root -> right);
    if (root -> right == NULL) return 1 + Number_of_node_that_has_1_leaf(root -> left);
    return Number_of_node_that_has_1_leaf(root -> left) + Number_of_node_that_has_1_leaf(root -> right);
}

int Number_of_node_that_has_2_leaf(NODE* root){
    if (root -> left == NULL && root -> right == NULL) return 0;
    if (root -> left == NULL ) return  Number_of_node_that_has_1_leaf(root -> right);
    if (root -> right == NULL) return  Number_of_node_that_has_1_leaf(root -> left);
    return 1 + Number_of_node_that_has_1_leaf(root -> left) + Number_of_node_that_has_1_leaf(root -> right);
}
bool CheckPerfect(int n) {
    int sum = 1; // Initialize the sum with 1 (since 1 is always a divisor)

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i * i != n) {
                sum += n / i;
            }
        }
    }

    return (sum == n);
}
int newproblem(NODE* root){
    if (root != NULL){
        if ( (root -> left == NULL && root -> right && CheckPerfect(root -> data) == true) || (root -> left && root -> right == NULL && CheckPerfect(root -> data) == true) )
            return 1 + newproblem(root -> left) + newproblem(root -> right);
        return newproblem(root -> left) + newproblem(root -> right);
        
    }
    else
        return 0;
}

bool SNT(int n) {
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

// NODE* findSmallestPrimeNODE(NODE* root) {
//     if (root -> data == )
// }

int oddRoot(NODE* root){
	if (root == NULL)
		return 0;
	return (root -> data % 2 == 1) + oddRoot(root -> left) + oddRoot(root -> right);
}

int count(NODE* root, int y, int x){
	if (root == NULL)
		return 0;
	return (root -> data > y  && root -> data < x) + count(root -> left,y ,x) + count(root -> right,y, x);
	
}

int oneLeaf(NODE* root){
	if (root == NULL)
		return 0;
	else{
		if ((root -> left == NULL && root -> right != NULL) || (root -> left != NULL &&root -> right == NULL))
            return 1 + oneLeaf(root ->left) + oneLeaf(root -> right);
        return oneLeaf(root ->left) + oneLeaf(root -> right);
	}
}
int main(){
    NODE* tree = NULL;
    create(tree);
    //NLR(tree); cout << endl;
    LNR(tree);cout << endl;
    //LRN(tree);cout << endl;
    //NRL(tree);cout << endl;
    //RNL(tree, 10);cout << endl;
    //RLN(tree);cout << endl;
    // cout << " b) Sum of all elements = "<<Sum_of_all_elements(tree) << endl;
    //cout << " c) The biggest value of tree = " << Max(tree) << endl;
    // Code to print the number of nodes in the tree goes here
    //cout <<"d) The numbers of node of tree = " << Number_of_node_of_tree(tree) << endl;
    //cout <<"e) The numbers of leaf of tree = " << Number_of_leaf_of_tree(tree) << endl;
    //cout <<"f) The number of node that has 1 leaf = " << Number_of_node_that_has_1_leaf(tree) <<" "<< oneLeaf(tree) << endl;
    //cout <<"g) The number of node that has 2 leaf = " << Number_of_node_that_has_2_leaf(tree) << endl;
    cout << count(tree, 45, 39);
    //cout << newproblem(tree);
    return 0;
}
