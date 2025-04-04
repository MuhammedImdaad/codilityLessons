
int solution(int A, int B, int K) {
    return B/K - (A ? (A-1)/K : -1); // 0 is always divisible
}