#include <vector>
using namespace std;

int solution(int M, vector<int> &A)
{
    vector<int> s(M + 1, 0);
    int out = 0, back = 0, front = 0, n = A.size();

    while (front < n)
    {
        if (s[A[front]] == 1) // duplicate
        {
            out += front - back;
            if (out > 1'000'000'000)
                return 1'000'000'000;
            s[A[back++]] = 0;
        }
        else
        {
            s[A[front++]] = 1;
        }
    }

    while (back < front) // cleanup
    {
        out += front - back;
        if (out > 1'000'000'000)
            return 1'000'000'000;
        back++;
    }

    return out;
}