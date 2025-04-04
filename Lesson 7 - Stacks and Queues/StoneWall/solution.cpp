#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> &H)
{
    stack<int> s;
    int out = 0;

    for (int h : H)
    {
        while (!s.empty() && s.top() > h) //higher walls
            s.pop();

        if (s.empty() || s.top() < h) //new wall
            s.push(h), out++;
    }

    return out;
}