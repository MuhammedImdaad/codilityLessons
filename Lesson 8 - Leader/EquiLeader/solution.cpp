#include <vector>
using namespace std;

int solution(vector<int> &A) {
    int count = 0, leader = A[0], out = 0, n = A.size();

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
    for (int val : A) 
    {
        if (val == leader)
            count++;
    }
    if (2 * count <= n)
        return out;

    int countL = 0, countR = count; //find equileaders
    for (int i = 0; i < n; i++)
    {
        if (A[i] == leader)
            countL++, countR--;
        
        if (
            2 * countL > (i+1) &&
            2 * countR > (n - i - 1)
        )
            out++;
    }
    
    return out;
}