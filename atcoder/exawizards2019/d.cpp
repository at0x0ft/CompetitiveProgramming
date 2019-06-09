#include <bits/stdc++.h>

#define MOD (long long int)1e9 + 7

using namespace std;

int main()
{
    int n, xi;
    scanf("%d %d", &n, &xi);

    vector<int> s(n), x;
    x.push_back(xi);
    int smin = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int si;
        scanf("%d", &si);
        s[i] = si;
        smin = min(smin, si);
    }
    sort(s.begin(), s.end());

    while (true)
    {
        auto maxxi = max_element(x.begin(), x.end());
        cerr << "[debug] : maxx = " << *maxxi << "\n"; // 4debug
        if (*maxxi < smin)
            break;

        while (s.back() > *maxxi)
            s.pop_back();

        int slen = s.size();
        for (int i = 0; i < slen; i++)
        {
            cerr << "[debug] : *maxxi = " << *maxxi << "\n";                // 4debug
            cerr << "[debug] : s[i] = " << s[i] << "\n";                    // 4debug
            cerr << "[debug] : *maxxi %% s[i] = " << *maxxi % s[i] << "\n"; // 4debug
            x.push_back(*maxxi % s[i]);
        }
        x.erase(maxxi);
    }

    long long int ans = 0;
    for (auto &&i : x)
    {
        ans += i;
        ans %= MOD;
    }

    printf("%lld\n", ans);

    return 0;
}
