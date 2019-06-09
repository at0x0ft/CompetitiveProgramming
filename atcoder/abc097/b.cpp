#include <bits/stdc++.h>

using namespace std;

int main()
{
    int X;

    scanf("%d", &X);

    int ans = 1, tmp;
    for (int i = 2; i < X; i++)
    {
        tmp = i;
        for (int j = 1; tmp <= X; j++)
        {
            tmp *= i;
            if (tmp <= X && tmp > ans)
            {
                ans = tmp;
            }
        }
        if (tmp == i * i)
        {
            break;
        }
    }

    printf("%d\n", ans);

    return 0;
}