// you can use includes, for example:
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int bucketsNeeded(vector<int> &A, int cap) {
    int buckets = 1;
    int curr = 0;
    for (int item : A)
    {
        if (curr + item > cap)
            buckets++, curr = item;
        else
            curr += item;
    }
    return buckets;
}

int solution(int K, int M, vector<int> &A) {
    int low = *max_element(A.begin(), A.end());
    int high = accumulate(A.begin(), A.end(), 0);

    while (low < high)
    {
        int mid = low + (high - low)/2;
        if (bucketsNeeded(A, mid) <= K)
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}