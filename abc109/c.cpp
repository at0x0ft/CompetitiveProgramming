#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1000000000

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
    int n, x;
    scanf("%d %d", &n, &x);

    int d;
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        if (i > 0)
            d = gcd(abs(a - x), d);
        else
            d = abs(a - x);
    }

    printf("%d\n", d);

    return 0;
}
