#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> &A)
{
    sort(A.begin(), A.end());
    int n = A.size();
    return max(
        A[0] * A[1] * A[n - 1], //top 3
        A[n - 3] * A[n - 2] * A[n - 1]); //top 1 with top negatives
}