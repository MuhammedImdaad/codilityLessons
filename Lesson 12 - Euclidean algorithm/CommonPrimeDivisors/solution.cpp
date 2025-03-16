// you can use includes, for example:
// #include <algorithm>
#include <vector>

using namespace std;

int gcd(int a, int b){
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}

int samePrimeDivisors(int x, int y) {
    int gcdG = gcd(x, y);
    
    while (x != 1) {
        int gcdX = gcd(x, gcdG);
        if (gcdX == 1)
            return false;
        x /= gcdX;
    }

    while (y != 1) {
        int gcdY = gcd(y, gcdG);
        if (gcdY == 1)
            return false;
        y /= gcdY;
    }

    return true;
}

int solution(vector<int> &A, vector<int> &B) {
    int out = 0;
    for (size_t i = 0; i < A.size(); i++)
    {
        out += samePrimeDivisors(A[i], B[i]);
    } 

    return out;
}