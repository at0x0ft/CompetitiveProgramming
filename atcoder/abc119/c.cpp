#include <bits/stdc++.h>

using namespace std;

#define MAX_N 8

int n, g[3], restn;
int dif[3][MAX_N];
int minLoc[3];

int gcd(const int x, const int y)
{
    if (x < y)
        return gcd(y, x);
    else if (x % y == 0)
        return y;
    else
        return gcd(y, x - y);
}

int findNewMin(const int gnum)
{
    int ans = 0, minimum = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int now = dif[gnum][i];
        if (now < INT_MAX)
        {
            int anow = abs(now);
            if (anow < minimum)
            {
                ans = i;
                minimum = anow;
            }
        }
    }
    return ans;
}

void refine(const int gnum, const int idx)
{
    for (int i = 0; i < n; i++)
    {
        dif[gnum][i] = INT_MAX;
    }

    for (int i = 0; i < 3; i++)
    {
        dif[i][idx] = INT_MAX;
        if (i != gnum && minLoc[i] == idx)
        {
            minLoc[i] = findNewMin(i);
        }
    }

    restn--;
}

void adjust(const int gnum)
{
    for (int i = 0; dif[gnum][minLoc[gnum]] + g[gnum] * i < g[gnum]; i++)
    {
    }
    while (dif[gnum][minLoc[gnum]])
        dif[gnum][minLoc[gnum]] += g[gnum];
}

void synth(const int gnum, const int idx)
{
    int tmp = dif[gnum][idx];
    dif[gnum][idx] = INT_MAX;

    for (int i = 0; i < 3; i++)
    {
        dif[i][idx] = INT_MAX;
        if (minLoc[i] == idx)
        {
            minLoc[i] = findNewMin(i);
        }
    }

    dif[gnum][minLoc[gnum]] += tmp;

    adjust(gnum);

    restn--;
}

int findMinIdx()
{
    int ans = 0, minimum = INT_MAX;
    for (int i = 0; i < 3; i++)
    {
        int now = dif[i][minLoc[i]];
        if (now < INT_MAX)
        {
            int anow = abs(now);
            if (anow < minimum)
            {
                ans = i;
                minimum = anow;
            }
        }
    }
    return ans;
}

int calcMinCost(const int cnt)
{
    if (cnt == 3)
        return 0;

    int midx = findMinIdx(), mini = minLoc[midx];
    int cnd = abs(dif[midx][mini]);
    cerr << "[debug] : cnd = " << cnd << ", restn = " << restn << "\n"; // 4debug
    if (cnd <= 10 || 3 - cnt + 1 == restn)
    {
        refine(midx, mini);
        return cnd + calcMinCost(cnt + 1);
    }
    else
    {
        synth(midx, mini);
        return 10 + calcMinCost(cnt);
    }
}

int main()
{
    scanf("%d %d %d %d", &n, &g[0], &g[1], &g[2]);
    restn = n;

    for (int i = 0; i < n; i++)
    {
        int l;
        scanf("%d", &l);
        for (int j = 0; j < 3; j++)
        {
            dif[j][i] = g[j] - l;
            if (abs(dif[j][i]) < abs(dif[j][minLoc[j]]))
                minLoc[j] = i;
        }
    }

    printf("%d\n", calcMinCost(0));

    return 0;
}
