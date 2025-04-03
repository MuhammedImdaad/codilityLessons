#include <stack>
#include <vector>
using namespace std;

int solution(vector<int> &A, vector<int> &B)
{
    stack<int> s;
    int eaten = 0, n = A.size();

    for (int i = 0; i < n; i++)
    {
        if (B[i]) //  downstream
            s.push(i);
        else // upstream
        {
            while (!s.empty() && A[s.top()] < A[i])
                s.pop(), eaten++;
            if (!s.empty())
                eaten++;
        }
    }

    return n - eaten;
}