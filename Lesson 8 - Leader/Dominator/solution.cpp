#include <vector>
using namespace std;

int solution(vector<int> &A) {
    if (A.empty())
        return -1;
        
    int count = 0, leader = A[0], out = -1, n = A.size();

    for (int val : A) //find the leader
    {
        if (count == 0)
            leader = val;
        if (val == leader)
            count++;
        else
            count--;
    }
    
    count = 0; //verify the leader
    for (int i = 0; i < n; i++) 
    {
        if (A[i] == leader)
            count++, out = i;
    }

    return (2 * count > n) ? out : -1;
}