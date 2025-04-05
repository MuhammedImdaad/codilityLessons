#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<int> &A)
{
    sort(A.begin(), A.end());
    int count = 0, n = A.size();

    for (int p = 0; p < n - 2; p++)
    {
        for (int q = p + 1; q < n - 1; q++)
        {
            int r = n - 1;
            while (q < r && A[p] + A[q] <= A[r])
                r--;
            count += r - q;
        }
    }
    
    return count;
}