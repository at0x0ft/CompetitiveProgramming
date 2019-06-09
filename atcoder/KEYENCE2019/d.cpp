#include <bits/stdc++.h>

using namespace std;

#define MAX_LEN 1000
const int MOD = 1e9 + 7;

long long int ans = 1;

void updateAns(int val)
{
    ans *= val;
    ans %= MOD;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    a[n] = 0;
    sort(a.begin(), a.end(), greater<int>());

    vector<int> b(m + 1);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }
    b[m] = 0;
    sort(b.begin(), b.end(), greater<int>());

    int ai = 0, bi = 0;
    for (int i = n * m; i >= 1; i--)
    {
        if (a[ai] > i || b[bi] > i)
        {
            ans = 0;
            break;
        }
        else if (a[ai] == i && b[bi] == i)
        {
            updateAns(1);
            ai++;
            bi++;
        }
        else if (a[ai] == i)
        {
            updateAns(bi);
            ai++;
        }
        else if (b[bi] == i)
        {
            updateAns(ai);
            bi++;
        }
        else
        {
            updateAns(ai * bi - (n * m - i));
        }
    }

    printf("%lld\n", ans);

    return 0;
}
