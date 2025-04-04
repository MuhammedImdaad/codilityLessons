#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> &A)
{
    sort(A.begin(), A.end());
    int req = 1;
    for (int val : A)
    {
        if (val > req)
            break;
        if (val == req)
            req++;
    }
    
    return req;
}