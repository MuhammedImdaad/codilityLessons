#include <vector>
using namespace std;

int solution(vector<int> &A)
{
    int out = 0;
    for (int val : A)
        out ^= val;
    return out;
}