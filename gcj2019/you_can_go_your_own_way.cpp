#include <bits/stdc++.h>

using namespace std;

vector<int> checkDiagonal(string &path)
{
    vector<int> ans;
    ans.push_back(0);
    int e = 0, s = 0;
    for (int i = 0; i < path.length(); i++)
    {
        if (path[i] == 'E')
            e++;
        else if (path[i] == 'S')
            s++;
        if (e == s)
            ans.push_back(e);
    }
    return ans;
}

void plusPathSame(string &ans, string &lp, const int i)
{
    if (lp[2 * i] == 'E')
        ans += "ES";
    else
        ans += "SE";
}

void plusPathDiff(string &ans, string &lp, const int i)
{
    if (lp[2 * i] == 'E')
        ans += "SE";
    else
        ans += "ES";
}

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        string lp;
        cin >> lp;

        auto dl = checkDiagonal(lp);
        int dl_idx = 0;

        string ans;
        for (int i = 0; i < n - 1; i++)
        {
            if (dl[dl_idx] == i)
            {
                plusPathDiff(ans, lp, i);
                dl_idx++;
            }
            else
                plusPathSame(ans, lp, i);
        }

        printf("Case #%d: ", i + 1);
        cout << ans << "\n";
    }

    return 0;
}
