#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }

    vector<int> ans;

    while (b.size() > 0)
    {
        for (int i = b.size() - 1; i >= 0; i--)
        {
            if (b[i] == i + 1)
            {
                ans.push_back(b[i]);
                b.erase(b.begin() + i);
                break;
            }
            else if (i == 0)
            {
                ans.push_back(-1);
                goto END;
            }
        }
    }

END:
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        printf("%d\n", ans[i]);
        if (ans[i] == -1)
            break;
    }

    return 0;
}
