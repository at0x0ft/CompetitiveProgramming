#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, X, ans = 0; // A[i][j] = A[i * N + j], (i * N + j) % N = j, / N = i;
    char S[90000];

    scanf("%d", &N);
    for (int i = 0; i < N * N; i++)
    {
        scanf(" %c", &(S[i]));
    }

    for (int A = 0; A < N; A++)
    {
        for (int B = 0; B < N; B++)
        {
            for (int i = 1; i < N; i++)
            {
                for (int j = 0; j < N - 1; j++)
                {
                    if (S[((i + A) % N) * N + ((j + B) % N)] != S[((j + A) % N) * N + ((i + B) % N)])
                        break;
                }
                if (i == N - 1)
                    ans++;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}