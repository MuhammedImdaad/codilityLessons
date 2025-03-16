
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> &A, vector<int> &B) {
    vector<int> out;

    vector<unsigned long>fibs;
    unsigned long first = 0, curr = 1;
    int L = *max_element(A.begin(), A.end()) + 1;
    while (L--)
    {
        fibs.push_back(curr);
        unsigned long next = first + curr;
        first = curr;
        curr = next;
    }

    for (size_t i = 0; i < A.size(); i++) {
        out.emplace_back (
            fibs[A[i]] % (1 << B[i])
        );
    }
    return out;
}