// you can use includes, for example:
// #include <algorithm>

int gcd(int a, int b){
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}

int solution(int N, int M) {
    // int lcm = (N*M)/gcd(N,M);
    // return lcm/M;
    return N/gcd(N,M);
}