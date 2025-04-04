#include <algorithm>
#include <vector>
using namespace std;

vector<int> solution(vector<int> &A, int K)
{
    if (A.empty())
        return A;

    reverse(A.begin(), A.end());
    reverse(A.begin(), A.begin() + K % A.size());
    reverse(A.begin() + K % A.size(), A.end());

    return A;
}