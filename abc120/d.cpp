#include <bits/stdc++.h>

using namespace std;

#define MAX_M 100000

int n, m;
int a[MAX_M], b[MAX_M], ans[MAX_M];

struct UnionFind
{
    vector<int> par;
    map<int, int> nn;

    UnionFind(int N) : par(N)
    {
        for (int i = 0; i < N; i++)
        {
            par[i] = i;
            nn[i] = 1;
        }
    }

    int root(const int x)
    {
        if (par[x] == x)
            return x;
        par[x] = root(par[x]);
        return par[x];
    }

    void unite(const int x, const int y)
    {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry)
            return;
        par[rx] = ry;
        nn[ry] += nn[rx];
    }

    bool same(const int x, const int y)
    {
        return root(x) == root(y);
    }

    int nodeNum(const int x)
    {
        return nn[root(x)];
    }
};

void updateAns(const int i, const int val)
{
    if (val == 0)
        return;
    else
    {
        for (int j = i; j < n; j++)
        {
            ans[j] += val;
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);

    int lim = (n * (n - 1)) / 2;

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &a[i], &b[i]);
    }

    UnionFind uf(n);

    for (int i = m - 1; i >= 0; i--)
    {
        if (uf.same(a[i], b[i]))
        {
            updateAns(i, 0);
        }
        else
        {
            updateAns(i, uf.nodeNum(a[i]) * uf.nodeNum(b[i]));
        }

        if (ans[m - 1] == lim)
            break;
    }

    for (int i = 0; i < m; i++)
    {
        printf("%d\n", ans[i]);
    }

    return 0;
}
