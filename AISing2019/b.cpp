#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, b, fcnt = 0, scnt = 0, tcnt = 0;
    scanf("%d %d %d", &n, &a, &b);

    for (int i = 0; i < n; i++)
    {
        int p;
        scanf("%d", &p);
        p <= a ? fcnt++ : (p <= b ? scnt++ : tcnt++);
    }

    printf("%d\n", min(fcnt, min(scnt, tcnt)));

    return 0;
}