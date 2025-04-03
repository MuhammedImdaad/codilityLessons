#include <stack>
#include <string>
using namespace std;

int solution(string &S)
{
    int N = S.size();
    stack<char> stack;

    for (int i = 0; i < N; i++)
    {
        if ((S[i] == '(') || (S[i] == '{') || (S[i] == '['))
        {
            stack.push(S[i]);
        }
        else
        {
            if (stack.empty())
                return 0;

            char peek = stack.top();
            if (
                ((peek == '(') && (S[i] == ')')) ||
                ((peek == '{') && (S[i] == '}')) ||
                ((peek == '[') && (S[i] == ']')))
                stack.pop();
            else
                return 0;
        }
    }

    return stack.empty() ? 1 : 0;
}