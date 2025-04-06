#include <vector>
using namespace std;

int solution(int K, vector<int> &A)
{
    int count = 0, len = 0;
    for (int rope : A)
    {
        len += rope;
        if (len >= K)
            count++, len = 0;
    }

    return count;
}