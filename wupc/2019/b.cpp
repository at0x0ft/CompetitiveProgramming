#include <bits/stdc++.h>

using namespace std;

int h, w;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

inline bool isRange(const int i, const int j)
{
    return 0 <= i && i < h && 0 <= j && j < w;
}

struct Area
{
    set<pair<int, int>> cells;

    Area(const int i, const int j)
    {
        cells.insert(pair<int, int>(i, j));
        for (int i = 0; i < 4; i++)
        {
            int cx = i + dx[i], cy = j + dy[i];
            if (isRange(cx, cy))
            {
                cells.insert(pair<int, int>(cx, cy));
            }
        }
    }

    // external methods
    bool isAdjacent(Area &a)
    {
        bool res = false;
        for (auto &&i : a.cells)
        {
            res |= cells.count(i) > 0;
        }
        return res;
    }

    void join(Area &a)
    {
        cells.insert(a.cells.begin(), a.cells.end());
    }
};

int fiveCnt = 0;
vector<Area> table[4]; // [0] : 0 ~ 4, [1] : 6, 7, [2] :  8, [3] : 9

int tidx(const int a)
{
    switch (a)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        return 0;
    case 5:
        return -1;
    case 6:
    case 7:
        return 1;
    case 8:
        return 2;
    case 9:
        return 3;
    }
}

void joinOrCreate(vector<Area> &dst, Area &src)
{
    for (int i = 0; i < dst.size(); i++)
    {
        if (src.isAdjacent(dst[i]))
        {
            src.join(dst[i]);
            dst.erase(dst.begin() + i);
            i--;
        }
    }
    dst.push_back(src);
}

int main()
{
    scanf("%d %d", &h, &w);

    int ma = -1, n = 0;
    bool j = false;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            int a;
            scanf("%d", &a);

            int idx = tidx(a);
            if (idx < 0)
                fiveCnt++;
            else
            {
                Area na(i, j);
                joinOrCreate(table[idx], na);
            }

            ma = max(a, ma);
        }
    }
    j |= ma == 0;
    j |= fiveCnt > 0;

    printf("%s", j ? "Yes" : "No");

    if (j)
    {
        for (int i = 3; i > 0; i--)
        {
            int tsize = table[i].size();
            for (int j = 0; j < tsize; j++)
            {
                joinOrCreate(table[i - 1], table[i][j]);
                n++;
            }
        }

        n++;
    }

    j ? printf(" %d\n", n) : printf("\n");

    return 0;
}
