#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<int> &A)
{
    sort(A.begin(), A.end());
    int out = 2'000'000'000;
    int i = 0, j = A.size() - 1;

    while (i <= j)
    {
        int sum = A[i] + A[j];
        out = min(out, abs(sum));
        if (sum > 0)
            j--;
        else
            i++;
    }
    
    return out;
}