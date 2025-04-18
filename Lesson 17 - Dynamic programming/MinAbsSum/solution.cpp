#include <vector>
#include <algorithm>
using namespace std;

/**
 * @brief Recursive function to calculate the minimum absolute sum of a subset.
 * 
 * @param i Current index in the array.
 * @param A Input array.
 * @param sum Current sum of the subset.
 * @return Minimum absolute sum of the subset.
 */
int rec(size_t i, vector<int> &A, int sum)
{
    if (i == A.size())
        return sum;

    return min(abs(rec(i + 1, A, sum - A[i])), abs(rec(i + 1, A, sum + A[i])));
}

/**
 * @brief Recursive function with memoization to calculate the minimum absolute sum of a subset.
 * 
 * @param i Current index in the array.
 * @param A Input array.
 * @param sum Current sum of the subset.
 * @param limit Maximum allowable sum.
 * @param dp Memoization table.
 * @return Minimum absolute sum of the subset.
 */
int rec(size_t i, vector<int> &A, int sum, int limit, vector<vector<int>> &dp)
{
    if (i == A.size())
        return sum;
    if (dp[i][sum] != -1)
        return dp[i][sum];
    int out = rec(i + 1, A, sum, limit, dp);
    if (sum + A[i] <= limit)
        out = max(out, rec(i + 1, A, sum + A[i], limit, dp));
    return dp[i][sum] = out;
}

/**
 * @brief Dynamic programming approach to calculate the minimum absolute sum of a subset.
 * 
 * @param A Input array.
 * @param limit Maximum allowable sum.
 * @return Minimum absolute sum of the subset.
 */
int dynamic(vector<int> &A, int limit)
{
    // vector<vector<int>> dp (A.size()+1, vector<int>(limit + 1, 0));
    vector<int> curr(limit + 1, 0);
    vector<int> prev(limit + 1, 0);

    for (int i = A.size(); i >= 0; i--)
    {
        for (int sum = 0; sum <= limit; sum++)
        {
            if (i == A.size())
                curr[sum] = sum;
            else
            {
                curr[sum] = prev[sum];
                if (sum + A[i] <= limit)
                    curr[sum] = max(prev[sum], prev[sum + A[i]]);
            };
        }

        prev = curr;
    }
    return prev[0];
}

/**
 * @brief Converts all elements in the array to their absolute values and calculates the total sum.
 * 
 * @param A Input array.
 * @return Total sum of the absolute values of the array elements.
 */
int convertToAbs(vector<int> &A)
{
    int sum = 0;
    for (auto &val : A)
    {
        if (val < 0)
            val = -1 * val;
        sum += val;
    }

    return sum;
}

/**
 * @brief Creates a count array representing the frequency of each element in the input array.
 * 
 * @param A Input array.
 * @return Count array where the index represents the element and the value represents its frequency.
 */
vector<int> createCountArray(vector<int> &A)
{
    int max = *max_element(A.begin(), A.end());
    vector<int> count(max + 1, 0);
    for (int val : A)
    {
        count[val]++;
    }

    return count;
}

/**
 * @brief Core dynamic programming function to calculate the possible subset sums.
 * 
 * @param counts Count array of the input elements.
 * @param sum Total sum of the input array.
 * @return DP array representing possible subset sums.
 */
vector<int> dynamicCore(vector<int> &counts, int sum)
{
    vector<int> dp(sum / 2 + 1, -1);
    dp[0] = 0;

    for (size_t i = 0; i < counts.size(); i++)
    {
        int count = counts[i];
        if (count > 0)
        {
            for (size_t j = 0; j < dp.size(); j++)
            {
                if (dp[j] >= 0)
                    dp[j] = count;
                else if (j >= i && dp[j - i] > 0)
                    dp[j] = dp[j - i] - 1;
            }
        }
    }

    return dp;
}

/**
 * @brief Calculates the minimum absolute difference between two subsets.
 * 
 * @param dp DP array representing possible subset sums.
 * @param sum Total sum of the input array.
 * @return Minimum absolute difference between two subsets.
 */
int minAbs(vector<int> &dp, int sum)
{
    for (int i = dp.size() - 1; i >= 0; i--)
    {
        if (dp[i] >= 0)
            return sum - 2 * i;
    }

    return -1;
}

/**
 * @brief Main solution function to calculate the minimum absolute sum of a subset.
 * 
 * @param A Input array.
 * @return Minimum absolute sum of a subset.
 */
int solution(vector<int> &A)
{
    // brute force recursion
    return rec(0, A, 0); // O(N^2) time

    // moving towards a dynamic approach
    int sum = convertToAbs(A);

    // vector<vector<int>> dp (A.size(), vector<int>(sum/2 + 1, -1));
    // int lower = rec(0, A, 0, sum/2, dp);
    int lower = dynamic(A, sum / 2);
    return sum - 2 * lower;

    // non-intuitive, yet most efficient dynamic approach, ~O(N^2)
    int sum = convertToAbs(A); 
    if (sum == 0)
        return sum;
    vector<int> counts = createCountArray(A);
    vector<int> dp = dynamicCore(counts, sum);
    return minAbs(dp, sum);
}