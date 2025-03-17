int solution(int N) {
    long out = 0, i = 1;

    while (i*i < N)
    {
        if (N%i==0)
            out+=2;
        i++;
    }

    if (i*i == N)
        out++;

    return out;
}