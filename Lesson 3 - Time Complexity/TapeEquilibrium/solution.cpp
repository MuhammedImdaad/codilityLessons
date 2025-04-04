#include <algorithm>
#include <limits>
#include <numeric>
#include <vector>
using namespace std;

int solution(vector<int> &A)
{
    int leftSum = 0;
    int rightSum = std::accumulate(A.begin(), A.end(), 0);   
    int minDiff = std::numeric_limits<int>::max();

    for (size_t i = 0; i < A.size() - 1; i++)
    {
        leftSum += A[i];
        rightSum -= A[i];
        int diff = std::abs(leftSum - rightSum);
        minDiff = std::min(minDiff, diff);
    }

    return minDiff;
}