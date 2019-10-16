#include <bits/stdc++.h>

using namespace std;

int count(vector<int> &h, const int l, const int r, const int minh)
{
    if (l == r)
        return h[l];

    int nl = -1, nminh = INT_MAX, ans = minh;
    for (int i = l; i <= r; i++)
    {
        h[i] -= minh;
        if (h[i] == 0)
        {
            if (nl >= 0)
            {
                ans += count(h, nl, i - 1, nminh);
                nl = -1;
                nminh = INT_MAX;
            }
            continue;
        }

        if (nl < 0)
        {
            nminh = h[i];
            nl = i;
        }
        else if (nl >= 0)
        {
            if (h[i] < nminh)
            {
                nminh = h[i];
            }
        }
    }

    if (nl >= 0)
        ans += count(h, nl, r, nminh);

    return ans;
}

int main()
{
    int n, min = INT_MAX, minI = -1;
    scanf("%d", &n);
    vector<int> h(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &h[i]);
        if (h[i] < min)
        {
            min = h[i];
            minI = i;
        }
    }

    printf("%d\n", count(h, 0, n - 1, min));

    return 0;
}