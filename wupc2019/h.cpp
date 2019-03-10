#include <bits/stdc++.h>

using namespace std;

long long int f0(const long long int x)
{
    switch (x % 4)
    {
    case 0:
        return x;
    case 1:
        return 1;
    case 2:
        return x + 1;
    case 3:
        return 0;
    }
}

int main()
{
    long long int a, b;
    scanf("%lld %lld", &a, &b);

    printf("%lld\n", a == 0 ? f0(b) : f0(a - 1) ^ f0(b));

    return 0;
}
