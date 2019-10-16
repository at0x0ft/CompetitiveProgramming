#include <bits/stdc++.h>

using namespace std;

#define MAX_M 100000

int n, m, ans = 0;
int x[MAX_M];

void solve()
{
    sort(x, x + n);
    int interval = (x[n - 1] - x[0]);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    }

    if (n < m)
        solve();

    printf("%d\n", ans);

    return 0;
}
