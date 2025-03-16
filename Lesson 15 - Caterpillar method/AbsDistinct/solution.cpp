#include <vector>
#include <cmath>
using namespace std;

int solution(vector<int> &A) {
    int n = A.size(), out = 0, low = 0, high = n - 1;

    while (low <= high)
    {
        auto left = abs(static_cast<long>(A[low]));
        auto right = abs(static_cast<long>(A[high]));
        
        if (left == right)
        {
            while (low <= high && abs(static_cast<long>(A[low])) == left)
                low++;
            while (low <= high && abs(static_cast<long>(A[high])) == right)
                high--;
        }
        else if (left < right)
        {
            while (low <= high && abs(static_cast<long>(A[high])) == right)
                high--;
        }
        else
        {
            while (low <= high && abs(static_cast<long>(A[low])) == left)
                low++;
        }
        
        out++;
    }

    return out;
}