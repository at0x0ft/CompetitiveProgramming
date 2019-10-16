#include <bits/stdc++.h>

using namespace std;

int gcd(const int x, const int y)
{
    if (x < y)
        return gcd(y, x);
    else if (x % y == 0)
        return y;
    else
        return gcd(y, x - y);
}

int main()
{
    int a, b, k;
    scanf("%d %d %d", &a, &b, &k);

    int g = gcd(a, b);

    double sg = sqrt(g);
    int cnt = 0, ans;
    for (int i = 1; i <= g; i++)
    {
        if (g % i == 0)
        {
            cnt++;
        }
        if (cnt == k)
        {
            ans = g / i;
            break;
        }
    }

    printf("%d\n", ans);

    return 0;
}
