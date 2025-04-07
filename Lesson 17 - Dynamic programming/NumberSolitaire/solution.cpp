#include <vector>
#include <limits>
using namespace std;

const int gMin = numeric_limits<int>::min();
int f(size_t i, vector<int> &a, vector<int> &dp)
{
    if (i == a.size() - 1)
        return a[i];

    if (dp[i] != gMin)
        return dp[i];

    int max = gMin;
    for (size_t j = 1; j < 7 && (i + j) < a.size(); j++)
    {
        max = std::max(max, f(i + j, a, dp));
    }

    return dp[i] = max + a[i];
}

int f(vector<int> &arr)
{
    auto n = arr.size();
    vector<int> dp(n, 0);
    dp[n - 1] = arr[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        int max = gMin;
        for (size_t j = 1; j < 7 && (i + j) < n; j++)
        {
            max = std::max(max, dp[i + j]);
        }
        dp[i] = max + arr[i];
    }
    return dp[0];
}

int solution(vector<int> &A)
{
    // top-down
    // vector<int>dp(A.size(), gMin);
    // return f(0, A, dp);

    // bottom-up
    return f(A);
}