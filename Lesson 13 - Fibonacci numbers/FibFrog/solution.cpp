#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void getFibs(vector<int>& fibs, int n) {
    int first = 0, curr = 1;
    while (curr <= n) {
        fibs.push_back(curr);
        int next = first + curr;
        first = curr;
        curr = next;        
    }
}

int solution(vector<int> &A) {
    int n = A.size();
    vector<int> fibs;
    getFibs(fibs, n + 1);

    queue<pair<int, int>> q; // {position, jumps}
    vector<bool> visited(n + 1, false);

    q.push({-1, 0});

    while (!q.empty()) {
        int pos = q.front().first;
        int jumps = q.front().second;
        q.pop();

        for (int fib : fibs) {
            int nextPos = pos + fib;
            int nextJump = jumps + 1;

            if (nextPos == n)
                return nextJump;

            if (nextPos > n || visited[nextPos] || A[nextPos] == 0)
                continue;

            visited[nextPos] = true;
            q.push({nextPos, nextJump});
        }
    }
    return -1;
}