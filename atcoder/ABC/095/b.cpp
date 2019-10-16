#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, X;

    scanf("%d %d", &N, &X);
    int min = X, buf;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &buf);
        X -= buf;
        if (buf < min)
            min = buf;
    }

    printf("%d\n", N + X / min);

    return 0;
}