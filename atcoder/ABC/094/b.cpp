#include <bits/stdc++.h>

#define MAX_M 100

using namespace std;

int main()
{
    int N, M, X, toH = 0, toT = 0, buf;

    scanf("%d %d %d", &N, &M, &X);
    for (int i = 1; i <= M; i++)
    {
        scanf("%d", &buf);
        if (buf < X)
            toH++;
        else if (buf > X)
            toT++;
    }

    printf("%d\n", min(toH, toT));

    return 0;
}