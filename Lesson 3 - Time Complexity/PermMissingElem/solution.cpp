#include <vector>
using namespace std;

int solution(vector<int> &A)
{
    int out = 0, n = A.size();
    
    for (int i = 0; i < n; i++)
        out ^= A[i] ^ (i + 1);

    out ^= n + 1;
    return out;
}