#include<iostream>
using namespace std;

int max(int a, int b){
    return a>b? a:b;
}
int algorithms_1_myAlgorithms(int a[], int n){
    int sum, maxOfTheProblem = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            sum = 0;
            for(int k=i; k <= j; k++){
                sum += a[k];
            }
            maxOfTheProblem = max(maxOfTheProblem, sum);
        }
    }
    return maxOfTheProblem;
}

int algorithms_2_myAlgorithms(int a[], int n){
    int sum, maxOfTheProblem=0;
    for(int i = 0; i < n; i++){
        sum = 0;
        for(int j = i; j < n; j++){
            sum += a[j];
            maxOfTheProblem = max(maxOfTheProblem, sum);
        }
    }
    return maxOfTheProblem;
}

int algorithms_3_myAlgorithms(int a[], int n){
    int maxSoFar = 0, maxEnding = 0; 
    for(int i = 0; i < n; i++){
        maxEnding = max( maxEnding + a[i], 0);
        maxSoFar = max(maxEnding, maxSoFar);
    }
    return  maxSoFar;
}

int main(){
    int n = 7;
    int a[n] = {4, -5, 6, -4, 2, 3, -7};
    cout << "a) " << algorithms_1_myAlgorithms(a, n) << endl;
    cout << "b) " << algorithms_2_myAlgorithms(a, n) << endl;
    cout << "c) " << algorithms_3_myAlgorithms(a, n) << endl;


    return 0;
}