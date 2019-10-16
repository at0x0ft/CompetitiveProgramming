#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100000

int n;
int cnt[MAX_N];

void cntAC(string &s)
{
    int slen = s.length(), ans = 0;
    for (int i = 0; i < slen - 1; i++)
    {
        if (s[i] == 'A' && s[i + 1] == 'C')
        {
            cnt[i + 1] = cnt[i] + 1;
        }
        else
            cnt[i + 1] = cnt[i];
    }
}

int main()
{
    int q;
    scanf("%d %d", &n, &q);

    string s;
    cin >> s;
    cntAC(s);

    for (int i = 0; i < q; i++)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        int ans = cnt[r - 1] - cnt[l - 1];
        printf("%d\n", ans);
    }

    return 0;
}
