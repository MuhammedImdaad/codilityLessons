#include <vector>

using namespace std;

vector<int> generatePrimes(int n) {
    vector<int> primes(n+1, 1);
    primes[0] = primes[1] = 0;

    for (int i = 2; i * i <= n; i++) {
        if (primes[i]) {
            for (int j = i * i; j <= n; j += i) {
                primes[j] = 0;
            }
        }
    }

    return primes; 
}

vector<int> generateSemiPrimes(int n, vector<int>& primes) {
    vector<int> semiPrimes(n+1, 0);

    for (int i = 2; i <= n; i++) {
        if (primes[i]) {
            for (int j = i; j <= n / i; j++) {  // Only check primes up to N / i
                if (primes[j]) {
                    int product = i * j;
                    if (product > n) break;  // Avoid going out of range
                    semiPrimes[product] = 1;
                }
            }
        }
    }

    return semiPrimes;
}

vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
    // Step 1: Generate primes using Sieve of Eratosthenes
    vector<int> primes = generatePrimes(N);

    // Step 2: Generate semiprimes
    vector<int> semiPrimes = generateSemiPrimes(N, primes);

    // Step 3: Create cumulative count of semiprimes
    for (int i = 1; i <= N; i++) {
        semiPrimes[i] += semiPrimes[i - 1];
    }

    // Step 4: Answer the queries
    vector<int> out(P.size());
    for (size_t i = 0; i < P.size(); i++) {
        out[i] = semiPrimes[Q[i]] - semiPrimes[P[i] - 1];
    }

    return out;
}