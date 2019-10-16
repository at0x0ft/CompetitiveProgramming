#include <bits/stdc++.h>

using namespace std;

bool canDev(long long int p, const long long int i, long long int n)
{
    while (n > 0)
    {
        if (p % i != 0)
            return false;
        else
            p /= i;
        n--;
    }
    return true;
}

int main()
{
    long long int n, p;
    scanf("%lld %lld", &n, &p);
    if (n == 1)
        printf("%lld\n", p);
    else
    {
        long long int ans = 1;
        for (long long int i = pow(p, 1.0 / n); i > 1; i--)
        {
            if (canDev(p, i, n))
            {
                ans = i;
                break;
            }
        }

        printf("%lld\n", ans);
    }

    return 0;
}