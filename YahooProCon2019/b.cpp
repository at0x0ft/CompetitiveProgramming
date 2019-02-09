#include <bits/stdc++.h>

using namespace std;

int main()
{
    int cnt[4] = {0};
    for (int i = 0; i < 3; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        cnt[a - 1]++;
        cnt[b - 1]++;
    }

    string ans = "YES";
    for (int i = 0; i < 4; i++)
    {
        if (cnt[i] >= 3)
        {
            ans = "NO";
            break;
        }
    }

    printf("%s\n", ans.c_str());

    return 0;
}
