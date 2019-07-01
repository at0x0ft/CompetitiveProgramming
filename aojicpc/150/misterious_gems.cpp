#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

#define MAX_N 20

int n, m;
int x[MAX_N], y[MAX_N];
int cnt;

void define_direction(const char d, const int l, int &lx, int &ly)
{
    switch (d)
    {
    case 'N':
        ly += l;
        break;
    case 'E':
        lx += l;
        break;
    case 'W':
        lx -= l;
        break;
    case 'S':
        ly -= l;
        break;
    default:
        break;
    }
}

bool is_range(const int x, const int y, const int z)
{
    if (x <= z)
        return x <= y && y <= z;
    else
        return z <= y && y <= x;
}

void move_and_check(pair<int, int> &r, char d, int l)
{
    int lx = 0, ly = 0;
    define_direction(d, l, lx, ly);
    REP(i, n)
    {
        if (is_range(r.first, x[i], r.first + lx) && is_range(r.second, y[i], r.second + ly))
        {
            x[i] = -1;
            y[i] = -1;
            cnt++;
        }
    }
    r.first += lx;
    r.second += ly;
    cerr << "[debug] : r.first = " << r.first << "\n";   // 4debug
    cerr << "[debug] : r.second = " << r.second << "\n"; // 4debug
}

int main()
{
    while (true)
    {
        cnt = 0;
        scanf("%d", &n);
        if (n == 0)
            break;

        REP(i, n)
        {
            scanf("%d %d", &x[i], &y[i]);
        }

        scanf("%d", &m);
        pair<int, int> r(10, 10);
        REP(i, m)
        {
            char d;
            int l;
            cin >> d >> l;
            move_and_check(r, d, l);
        }

        printf("%s\n", cnt == m ? "Yes" : "No");
    }

    return 0;
}
