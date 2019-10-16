#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, xl, yl;
    scanf("%d %d %d %d", &n, &m, &xl, &yl);

    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        xl = max(xl, x);
    }

    for (int i = 0; i < m; i++)
    {
        int y;
        scanf("%d", &y);
        yl = min(yl, y);
    }

    printf("%s\n", xl < yl ? "No War" : "War");

    return 0;
}
