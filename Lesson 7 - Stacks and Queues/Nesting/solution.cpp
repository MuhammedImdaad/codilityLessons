#include <string>
using namespace std;

int solution(string &S)
{
    int opened = 0;
    for (char c : S)
    {
        if (c == '(')
            opened++;
        else
            opened--;

        if (opened < 0)
            return 0;
    }

    return opened == 0 ? 1 : 0;
}