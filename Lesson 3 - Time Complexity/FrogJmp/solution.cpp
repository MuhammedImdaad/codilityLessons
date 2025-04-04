int solution(int X, int Y, int D)
{
    int dist = Y - X;

    return dist % D ? dist / D + 1 : dist / D;
}