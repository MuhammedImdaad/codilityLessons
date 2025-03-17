#include <vector>
using namespace std;

int solution(vector<int> &A) {
    auto n = A.size();
    vector<int> left(n, 0);
    vector<int> right(n, 0);

    for (size_t i = 1; i < n-1; i++)
    {
        left[i] = max(left[i-1] + A[i], 0);
    }

    for (int i = n - 2; i > 0; i--)
    {
        right[i] = max(right[i+1] + A[i], 0);
    }   
    
    int out = 0;
    for (size_t i = 1; i < n-1; i++)
    {
        out = max(out, left[i-1] + right[i+1]);
    }
    
    return out;
}