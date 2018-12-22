#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, h, w;
    scanf("%d %d %d", &n, &h, &w);

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if (h <= a && w <= b)
            cnt++;
    }

    printf("%d\n", cnt);

    return 0;
}