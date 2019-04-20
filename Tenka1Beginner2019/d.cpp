#include <bits/stdc++.h>

#define MOD 1000000000 + 7

using namespace std;
struct CinInit
{
    CinInit()
    {
        cin.tie(0);
        ios::sync_with_stdio(0);
        cout << fixed << setprecision(20);
    };
} CinInit;

int main()
{
    int n;
    scanf("%d", &n);

    long long int ans;
    if (n == 3)
    {
        ans = 61;
    }
    else if (n >= 4)
    {
    }
    printf("%lld\n", ans);

    return 0;
}
