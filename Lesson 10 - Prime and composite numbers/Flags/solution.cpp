// #include <algorithm>
#include <vector>
using namespace std;

// place flags
bool canPlace(vector<int>& peaks, int flags) {
    int prev = -1, count = flags;
    
    for (int peak : peaks)
    {
        if (prev == -1 || (peak - prev >= flags))
            count--, prev = peak;
        if (count == 0)
            return true;
    }
    
    return false;
}

int solution(vector<int> &A) {
    // get the peaks
    vector<int> peaks;
    int n = A.size();
    for (int i = 1; i < n - 1; i++) {
        if (A[i-1] < A[i] && A[i+1] < A[i])
            peaks.emplace_back(i);
    }

    // pick flags 1 - /N
    int low = 1, high = peaks.size() + 1;
    while (low < high)
    {
        int mid = (low + high)/2;
        
        if (canPlace(peaks, mid))
            low = mid + 1;
        else
            high = mid;
    }

    return n == 1 ? 0 : low - 1;
}