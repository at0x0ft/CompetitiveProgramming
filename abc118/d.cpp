#include <bits/stdc++.h>

using namespace std;

#define MAX_N 10000 + 1
#define CV_TABLE_LEN 8

int n, m, a;
vector<int> dp[MAX_N] = {vector<int>()};
int cvtable[CV_TABLE_LEN]; // cvtable[cost] = value;

void inputCVTable(const int n)
{
    switch (n)
    {
    case 1:
        cvtable[2] = max(cvtable[2], n);
        break;
    case 2:
        cvtable[5] = max(cvtable[5], n);
        break;
    case 3:
        cvtable[5] = max(cvtable[5], n);
        break;
    case 4:
        cvtable[4] = max(cvtable[4], n);
        break;
    case 5:
        cvtable[5] = max(cvtable[5], n);
        break;
    case 6:
        cvtable[6] = max(cvtable[6], n);
        break;
    case 7:
        cvtable[3] = max(cvtable[3], n);
        break;
    case 8:
        cvtable[7] = max(cvtable[7], n);
        break;
    case 9:
        cvtable[6] = max(cvtable[6], n);
        break;
    default:
        break;
    }
}

vector<int> cmp(vector<int> &a, vector<int> &b)
{
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    int alen = a.size(), blen = b.size();
    if (alen < blen)
        return b;
    else if (alen > blen)
        return a;
    else
    {
        for (int i = 0; i < alen; i++)
        {
            if (a[i] < b[i])
                return b;
            else if (a[i] > b[i])
                return a;
        }
    }
    return a;
}

void printans()
{
    int s = dp[n].size();
    for (int i = 0; i < s; i++)
    {
        printf("%d", dp[n][i]);
    }
    printf("\n");
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a;
        scanf("%d", &a);
        inputCVTable(a);
    }

    // i = 0
    for (int j = 0; j < CV_TABLE_LEN; j++)
    {
        if (cvtable[j] > 0)
            dp[j].push_back(cvtable[j]);
    }

    for (int i = 1; i <= n; i++)
    {
        if (dp[i].size() == 0)
            continue;

        for (int j = 0; j < CV_TABLE_LEN; j++)
        {
            if (cvtable[j] > 0 && i + j <= n)
            {
                vector<int> v = dp[i];
                v.push_back(cvtable[j]);
                dp[i + j] = cmp(dp[i + j], v);
            }
        }
    }

    printans();
    return 0;
}
