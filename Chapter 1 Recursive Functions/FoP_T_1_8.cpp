#include<iostream>
using namespace std;
int C(int k, int n){
	if ( k == n || k == 0) return 1;
	return C(k-1, n-1) + C(k, n-1);
}
void De_Recursion_Pascal_Triangle(int h){
	for (int n=0; n < h; n++){
		for (int i=1; i <= h-(n+1); i++){
			cout <<" ";
		}
		for (int k=0; k <= n; k++){
			cout << C(k,n) <<" ";
		}
		cout << endl;
	}
}
int main(){
	int k, n, h;
	cout <<"Enter k: "; cin >> k;
	cout <<"Enter n: "; cin >> n;
	cout <<"Enter h: "; cin >> h;
	cout << "a) C(" << k <<"," <<n<<") = " << C(k,n) << endl;
	cout << "b) De-recursion Pascal's triangle: " << endl;
	De_Recursion_Pascal_Triangle(h);
	return 0;
}