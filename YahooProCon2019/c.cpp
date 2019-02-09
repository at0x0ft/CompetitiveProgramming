#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int k, a, b;
    scanf("%lld %lld %lld", &k, &a, &b);

    if (k <= a || b - a <= 1)
        printf("%lld\n", k + 1);
    else
    {
        printf("%lld\n", a + ((k - a + 1) / 2) * (b - a) + ((k - a + 1) % 2));
    }

    return 0;
}
