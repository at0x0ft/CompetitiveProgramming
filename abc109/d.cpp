#include <bits/stdc++.h>

using namespace std;

#define MAX_H 500
#define MAX_W 500

int h, w;
int table[MAX_H][MAX_W];

string printQuery(const int fromY, const int fromX, const int toY, const int toX)
{
    return to_string(fromY + 1) + " " + to_string(fromX + 1) + " " + to_string(toY + 1) + " " + to_string(toX + 1);
}

int main()
{
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            int a;
            scanf("%d", &a);
            table[i][j] = a;
        }
    }

    vector<string> ans;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (table[i][j] % 2 == 1)
            {
                if (j + 1 < w)
                {
                    table[i][j]--;
                    table[i][j + 1]++;
                    ans.push_back(printQuery(i, j, i, j + 1));
                }
                else if (i + 1 < h)
                {
                    table[i][j]--;
                    table[i + 1][j]++;
                    ans.push_back(printQuery(i, j, i + 1, j));
                }
            }
        }

        i++;

        if (i < h)
        {
            for (int j = w - 1; j >= 0; j--)
            {
                if (table[i][j] % 2 == 1)
                {
                    if (j - 1 > 0)
                    {
                        table[i][j]--;
                        table[i][j - 1]++;
                        ans.push_back(printQuery(i, j, i, j - 1));
                    }
                    else if (i + 1 < h)
                    {
                        table[i][j]--;
                        table[i + 1][j]++;
                        ans.push_back(printQuery(i, j, i + 1, j));
                    }
                }
            }
        }
    }

    int n = ans.size();
    printf("%d\n", n);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << "\n";
    }

    return 0;
}
