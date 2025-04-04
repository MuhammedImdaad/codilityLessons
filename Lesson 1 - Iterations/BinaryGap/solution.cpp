#include <algorithm>
using namespace std;

int solution(int N)
{
    while (N && (N & 1) == 0) // remove trailing zero bits
        N >>= 1;

    int maxGap = 0;
    while (N)
    {
        N >>= 1;
        int currGap = 0;
        while (N && (N & 1) == 0) // remove zero bits
            N >>= 1, currGap++;

        maxGap = max(maxGap, currGap);
    }
    return maxGap;
}