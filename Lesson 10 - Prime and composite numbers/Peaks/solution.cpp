#include <vector>
using namespace std;

bool canPlace(int blocks, vector<int>& peaks, int n)
{
    if (n % blocks)
        return false;
    
    int blockSize = n/blocks;
    int i = 0, j = 0;
    
    while (i < blocks && j < peaks.size())
    {
        int start = i * blockSize, end = (i + 1) * blockSize-1;
        if (peaks[j] < start)
            j++;
        else if (end < peaks[j])
            return false;
        else
            i++;
    }

    return i == blocks;
}

int solution(vector<int> &A) {
    // get peaks
    // iterate blocks max to 1
    // check if can be filled with peaks
    vector<int> peaks;
    int n = A.size();

    for (int i = 1; i < n - 1; i++)
    {
        if (A[i-1] < A[i] && A[i] > A[i+1])
            peaks.push_back(i);
    }

    for (int blocks = peaks.size(); blocks > 0; blocks--)
    {
        if (canPlace(blocks, peaks, n))
            return blocks;
    }

    return 0;
}