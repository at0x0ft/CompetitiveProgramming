#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, c;
    scanf("%d %d %d", &n, &m, &c);
    vector<int> b(m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int k = c;
        for (int j = 0; j < m; j++)
        {
            int a;
            scanf("%d", &a);
            k += a * b[j];
        }
        if (k > 0)
            cnt++;
    }

    printf("%d\n", cnt);

    return 0;
}
