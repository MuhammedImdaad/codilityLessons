#include <vector>
using namespace std;

vector<int> solution(int N, vector<int> &A)
{
    vector<int> counter(N, 0);
    int currMax = 0, limit = 0;

    for (int val : A)
    {
        if (val == N + 1)
        {
            limit = currMax;
        }
        else
        {
            auto &currCount = counter[val - 1];
            currCount = std::max(currCount, limit) + 1;
            currMax = std::max(currMax, currCount);
        }
    }

    for (auto &val : counter)
    {
        val = std::max(val, limit);
    }

    return counter;
}