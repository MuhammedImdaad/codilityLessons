#include <vector>
using namespace std;

int solution(vector<int> &A)
{
    double minAvg = 10'000, out = 0, n = A.size();

    for (int i = 0; i < n - 2; i++)
    {
        double slice2 = (A[i] + A[i + 1]) / 2.0;
        double slice3 = (A[i] + A[i + 1] + A[i + 2]) / 3.0;
        double curr = min(slice2, slice3);
        if (curr < minAvg)
            minAvg = curr, out = i;
    }

    double last = (A[n - 2] + A[n - 1]) / 2.0;
    return last < minAvg ? n - 2 : out;
}