#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> f(m, 0);
    for (int i = 0; i < n; i++)
    {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++)
        {
            int a;
            scanf("%d", &a);
            f[a - 1]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        if (f[i] == n)
            ans++;
    }

    printf("%d\n", ans);

    return 0;
}
