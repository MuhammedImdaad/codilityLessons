#include <vector>
using namespace std;

int solution(vector<int> &A) {
    int buy = 200'000, profit = 0;

    for (int val : A)
    {
        buy = min(buy, val);
        profit = max(profit, val - buy);
    }

    return profit;
}