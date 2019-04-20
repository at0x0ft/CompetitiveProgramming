#include <bits/stdc++.h>

using namespace std;

#define MAX_N 50000
#define MAX_M 20

#define FOR() for (int i =)

int n, m;
int c[MAX_M];
int dp[MAX_N + 1];

inline bool isRange(const int k)
{
    return 0 <= k && k <= n;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &c[i]);
    }

    memset(dp, INT_MAX, sizeof(dp));

    dp[0] = 0;
    // 4debug
    for (int i = 0; i < n; i++)
    {
        cerr << "[debug] : dp[" << i << "] = " << dp[i] << "\n"; // 4debug
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (isRange(i + c[j]))
                dp[i + c[j]] = min(dp[i] + 1, dp[i + c[j]]);
        }
    }

    printf("%d\n", dp[n]);

    return 0;
}
