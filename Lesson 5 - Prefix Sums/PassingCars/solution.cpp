#include <vector>
using namespace std;

int solution(vector<int> &A)
{
    int out = 0, east = 0;

    for (int val : A)
    {
        if (val == 1) // west
        {
            out += east;
            if (out > 1'000'000'000)
                return -1;
        }
        else // east
        {
            east++;
        }
    }

    return out;
}