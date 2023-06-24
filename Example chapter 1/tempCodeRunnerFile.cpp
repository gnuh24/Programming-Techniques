long long Problem_d(int n){
    if (n == 0) return 0;
    return (n % 2 + 10 * Problem_d(n/2));
}