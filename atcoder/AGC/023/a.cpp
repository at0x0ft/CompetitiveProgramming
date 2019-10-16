#include <bits/stdc++.h>

#define DIV 10e9 + 7

using namespace std;

long long int fact(int N)
{
    if (N == 0)
        return 1;
    else
        return (long long int)N * fact(N - 1) % DIV;
}

int solveO(int N)
{
    long long int fn2 = fact((N - 1) / 2), ans = (N + 1) * fn2 * (N + 1) / 2;
    ans % = DIV;
    for (int i = 1; i < (N - 1) / 2; i++)
    {
        ans += fact((N - 1) / 2 + i - 1) * 2 * ((N + 1) / 2 + i - 1);
    }
}

int main()
{
    int N;

    scanf("%d", &N);

    switch (N % 2)
    {
    case 1:
        solveO(N);
        break;
    case 0:
        solveE(N);
        break;
    }

    vector<long long int> A(N);
    long long int all = 0;

    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &(A[i]));
        all += A[i];
    }

    int sum;
    long long int ans = 0;

    for (int i = 0; i < N - i; i++)
    {
        sum = 0;
        if (all == 0)
        {
            ans++;
        }

        for (int j = i; j < N - i - 1; j++)
        {
            sum += A[j];
            if (sum == 0)
            {
                fprintf(stderr, "debug print : sum = (i, j) = (%d, %d)\n", i, j); // 4debug
                ans++;
            }

            if (all == sum)
            {
                fprintf(stderr, "debug print : ~sum = (i, j) = (%d, %d)\n", i, j); // 4debug
                ans++;
            }
        }
        all -= (A[i] + A[N - i - 1]);
    }

    printf("%lld\n", ans);

    return 0;
}