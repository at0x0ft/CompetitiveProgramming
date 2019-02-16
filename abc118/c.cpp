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
    int n;
    scanf("%d", &n);
    int a0;
    scanf("%d", &a0);
    for (int i = 1; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        a0 = gcd(a, a0);
    }

    printf("%d\n", a0);

    return 0;
}
