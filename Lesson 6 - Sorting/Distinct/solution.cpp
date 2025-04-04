#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> &A) {
    sort(A.begin(), A.end());
    int dis = 0;
    for (size_t i = 1; i < A.size(); i++)
    {
        if (A[i] != A[i-1])
            dis++;
    }

    return A.empty() ? 0 : dis+1;
}