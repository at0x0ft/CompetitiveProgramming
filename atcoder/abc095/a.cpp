#include <bits/stdc++.h>

using namespace std;

int main()
{
    char S[4];
    int ans = 700;

    scanf("%s", S);

    for (int i = 0; i < 3; i++)
    {
        if (S[i] == 'o')
            ans += 100;
    }

    printf("%d\n", ans);

    return 0;
}