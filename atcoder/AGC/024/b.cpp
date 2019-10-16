#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, ans, c, aix, bix, max = -1;
    scanf("%d", &N);

    vector<int> P(N);
    vector<int> Pc(N, 1);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &P[i]);
    }

    int tmp, dtmp;

    for (int i = 0; i < N; i++)
    {
        if (Pc[i] == 1)
        {
            tmp = P[i];
            dtmp = P[i];
            ans = 0;
            for (int j = i; j < N; j++)
            {
                if (Pc[j] == 1 && tmp == P[j])
                {
                    ans++;
                    Pc[j] = 0;
                    tmp++;
                }
                else if (P[j] < P[i] && dtmp - ans <= P[j])
                {
                    dtmp = P[j];
                    Pc[j] = 0;
                }
            }
            if (ans > max)
            {
                max = ans;
            }
        }
    }

    printf("%d\n", N - max);

    return 0;
}