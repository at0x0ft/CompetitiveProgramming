#include <bits/stdc++.h>

using namespace std;

#define MAX_LEN 400

int h, w;
char mat[MAX_LEN][MAX_LEN];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

inline bool isRange(const int i, const int j)
{
    return 0 <= i && i <= h && 0 <= j && j <= w;
}

inline int ld(const int i1, const int i2, const int j1, const int j2)
{
    return abs(i1 - i2) + abs(j1 - j2);
}

int solve(const int si, const int sj, const int ci, const int cj, const int d)
{
    // fprintf(stderr, "debug print : si, sj, ci, cj, d = %d, %d, %d, %d, %d\n", si, sj, ci, cj, d); // 4debug

    int cnd = 0;
    for (int i = 0; i < 4; i++)
    {
        // fprintf(stderr, "debug print [search] : ci + dx[i], cj + dy[i] = %d, %d, d = %d, T/F ? : %d\n", ci + dx[i], cj + dy[i], d, mat[ci + dx[i]][cj + dy[i]] == (d % 2 == 1 ? '.' : '#')); // 4debug
        if (isRange(ci + dx[i], cj + dy[i]) && mat[ci + dx[i]][cj + dy[i]] == (d % 2 == 1 ? '.' : '#') && ld(si, ci + dx[i], sj, cj + dy[i]) == d)
        {
            mat[ci + dx[i]][cj + dy[i]] = 'x';

            if (d % 2 == 1)
                cnd++;
            fprintf(stderr, "debug print : si, sj, ci, cj = %d, %d, %d, %d\n", si, sj, ci + dx[i], cj + dy[i]); // 4debug
            cnd += solve(si, sj, ci + dx[i], cj + dy[i], d + 1);
        }
    }
    return cnd;
}

void countNext(set<pair<pair<int, int>, pair<int, int>>> &sgSet, const int ci, const int cj)
{
    for (int i = 0; i < 4; i++)
    {
        if (isRange(ci + dx[i], cj + dy[i]) && mat[ci + dx[i]][cj + dy[i]] == '.')
        {
            sgSet.insert(make_pair(make_pair(ci, cj), make_pair(ci + dx[i], cj + dy[i])));
        }
    }
}

void connect(set<pair<pair<int, int>, pair<int, int>>> &sgSet, pair<pair<int, int>, pair<int, int>> fst, pair<pair<int, int>, pair<int, int>> snd)
{
    sgSet.insert(make_pair(fst.first, snd.second));
}

int main()
{
    scanf("%d %d", &h, &w);

    for (int i = 0; i < h; i++)
    {
        scanf("%s", mat[i]);
        mat[i][w] = '\0';
    }

    int cnt = 0;
    set<pair<pair<int, int>, pair<int, int>>> sgSet;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (mat[i][j] == '#')
            {
                countNext(sgSet, i, j);
            }
        }
    }

    while (true)
    {
        int nowCount = sgSet.size();
    }

    printf("%d\n", cnt);

    return 0;
}