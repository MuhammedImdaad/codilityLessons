// you can use includes, for example:
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<int> &A) {
    unordered_map<int,int> counts;
    for (auto val : A)
        counts[val]++;

    int max = *max_element(A.begin(), A.end());
    vector<int> factors(max+1, 0);

    for (auto& it : counts)
    {
        int factor = it.first, count = it.second;
        for (int j = factor; j < max + 1; j += factor)
        {
            factors[j] += count;
        }
    }

    int n = A.size();
    vector<int> out(n);
    for (int j = 0; j < n; j++)
    {
        out[j] = n - factors[A[j]];
    }

    return out;
}