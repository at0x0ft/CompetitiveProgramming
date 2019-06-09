#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<pair<long long int, long long int>> ab(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld %lld", &(ab[i].first), &(ab[i].second));
    }

    sort(ab.begin(), ab.end());

    long long int ans = 0;
    for (int i = 0; m > 0; i++)
    {
        if (m > ab[i].second)
        {
            ans += ab[i].first * ab[i].second;
            m -= ab[i].second;
        }
        else
        {
            ans += ab[i].first * m;
            break;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
