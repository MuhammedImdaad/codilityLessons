#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> &A) {
    int n = A.size();
    std::sort(A.begin(), A.end());

    for (int i = 0; i < n - 2; i++) {
        // Triangle condition: A[i] + A[i+1] > A[i+2]
        if (A[i] > 0 && A[i] + (long)A[i+1] > A[i+2]) {
            return 1;
        }
    }

    return 0;
}