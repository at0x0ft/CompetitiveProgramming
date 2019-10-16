#include <bits/stdc++.h>

using namespace std;

#define MAX_L 200000

int l;
int a[MAX_L];

int main()
{
    scanf("%d", &l);
    int elen = 0, olen = 0, elenmax = INT_MIN, olenmax = INT_MIN;
    for (int i = 0; i < l; i++)
    {
        int buf;
        scanf("%d", &buf);
        if (buf == 0)
            a[i] = -1;
        else
            a[i] = buf % 2;
    }

    for (int i = 0; i < q; i++)
    {
        scanf("%d %d", &a, &b);
        ans = 0;
        for (int j = 0; j < m; j++)
        {
            if (len[j].first <= b - a && a <= len[j].second && b >= len[j].first + len[j].second)
                ans++;
            else if (len[j].first > b - a)
                break;
        }
        printf("%d\n", ans);
    }

    return 0;
}
