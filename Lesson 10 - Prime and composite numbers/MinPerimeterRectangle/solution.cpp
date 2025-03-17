// you can use includes, for example:
#include <algorithm>
#include <limits>
using namespace std;

int solution1(int N) {
    int low = 1, high = N;
    while (low < high)
    {
        long mid = (low + high)/2;
        if (mid * mid > N)
            high = mid;
        else
            low = mid + 1;
    }

    int i = N == 1 ? 1 : low - 1;

    while (i)
    {
        if (N%i == 0)
            return 2 * (i + N/i);
        i--;
    }

    return 0;
}

int solution2(int N) {
    int i = 1, perim = numeric_limits<int>::max();

    while (i * i <= N)
    {
        if (N%i == 0)
        {
            perim = min(perim, 2 * (i + N/i));
        }
        i++;
    }

    return perim;
}

int solution(int N) {
    // return solution1(N);
    return solution2(N);
}