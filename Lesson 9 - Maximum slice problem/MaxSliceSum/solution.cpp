#include <vector>
using namespace std;

int solution(vector<int> &A) {
    int out = A[0]; // Initialize with first element
    int currSum = A[0];

    for (size_t i = 1; i < A.size(); i++) {
        currSum = max(A[i], currSum + A[i]); // Either start new subarray or extend current
        out = max(out, currSum); // Update max sum
    }

    return out;   
}