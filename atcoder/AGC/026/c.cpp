#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, ans = 0, tmp;
    scanf("%d", &N);

    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    if (A[0] != 0)
        ans = -1;
    else
    {
        for (int i = 1; i < N; i++)
        {
            if (A[i] > A[i - 1])
                ans += A[i] - A[i - 1];
            else
            {
                ans += A[i];
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}