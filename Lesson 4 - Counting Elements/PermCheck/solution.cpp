#include <vector>
using namespace std;

int solution(vector<int> &A)
{
    int out = 0;
    for (size_t i = 0; i < A.size(); i++)
    {
        out ^= A[i] ^ (i + 1);
    }

    return out ? 0 : 1;
}