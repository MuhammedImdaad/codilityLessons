#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<int> &A)
{
    vector<long> begin, end;
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        begin.push_back((long)i - A[i]);
        end.push_back((long)i + A[i]);
    }

    sort(begin.begin(), begin.end());
    sort(end.begin(), end.end());

    int out = 0, active = 0, j = 0;
    for (int i = 0; i < n; i++)
    {
        //update active list
        while (j < n && begin[i] > end[j])
            active--, j++;
        out += active++;

        if (out > 10'000'000)
            return -1;
    }
    return out;
}