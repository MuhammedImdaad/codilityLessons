#include <algorithm>
#include <vector>

using namespace std;

bool canNailAll(int mid, int max, vector<int> &A, vector<int> &B, vector<int> &C)
{
    vector<int> prefix(max + 1, 0);
    for (int i = 0; i <= mid; i++)
    {
        if (C[i] < max + 1)
            prefix[C[i]] = 1;
    }

    for (int i = 1; i < max + 1; i++)
    {
        prefix[i] += prefix[i - 1];
    }

    for (int i = 0; i < A.size(); i++)
    {
        if (prefix[B[i]] <= prefix[A[i] - 1]) // if no nail is getting hammered in the plank
            return false;
    }
    return true;
}

int solution(vector<int> &A, vector<int> &B, vector<int> &C)
{
    int max = *max_element(B.begin(), B.end());
    int low = 0, high = C.size();

    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (canNailAll(mid, max, A, B, C))
            high = mid;
        else
            low = mid + 1;
    }

    return low == C.size() ? -1 : low + 1;
}