#include <vector>
using namespace std;

int solution(int X, vector<int> &A)
{
    vector<int> leafs(X + 1, 0);
    int count = 0, n = A.size();

    for (int i = 0; i < n; i++)
    {
        if (leafs[A[i]] == 0)
        {
            leafs[A[i]] = 1;
            count++;
            if (count == X)
                return i;
        }
    }
    return -1;
}