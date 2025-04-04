#include <vector>
#include <string>
using namespace std;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q)
{
    vector<vector<int>> count(4, vector<int>(S.size() + 1, 0));

    for (unsigned int i = 0; i < S.size(); i++)
    {
        count[0][i + 1] = S[i] == 'A' ? count[0][i] + 1 : count[0][i];
        count[1][i + 1] = S[i] == 'C' ? count[1][i] + 1 : count[1][i];
        count[2][i + 1] = S[i] == 'G' ? count[2][i] + 1 : count[2][i];
        count[3][i + 1] = S[i] == 'T' ? count[3][i] + 1 : count[3][i];
    }

    vector<int> out(P.size());

    for (unsigned int i = 0; i < P.size(); i++) // query
    {
        for (unsigned int j = 0; j < count.size(); j++) // nucleotides
        {
            vector<int> &nuc = count[j];
            if (nuc[Q[i] + 1] > nuc[P[i]]) // nuc exist
            {
                out[i] = j + 1;
                break;
            }
        }
    }

    return out;
}