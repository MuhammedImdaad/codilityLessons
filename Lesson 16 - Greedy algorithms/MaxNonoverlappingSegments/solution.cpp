#include <vector>
using namespace std;

int solution(vector<int> &A, vector<int> &B)
{
    int end = -1, count = 0;

    for (size_t i = 0; i < A.size(); i++)
    {
        // to maximize non-overlapping segments,
        //  we always want to choose the one that ends earliest
        if (end < A[i])
            end = B[i], count++;
    }

    return count;
}