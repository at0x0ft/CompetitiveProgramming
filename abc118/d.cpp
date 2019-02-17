#include <bits/stdc++.h>

using namespace std;

#define MAX_N 10000 + 1

int n, m, a;
string dp[MAX_N];
map<int, char> cvmap; // cvmap[cost] = value;

int getCost(const char value)
{
    switch (value)
    {
    case '1':
        return 2;
    case '7':
        return 3;
    case '4':
        return 4;
    case '2':
    case '3':
    case '5':
        return 5;
    case '6':
    case '9':
        return 6;
    case '8':
        return 7;
    default:
        return 0;
    }
}

void inputCVMap(const char value)
{
    int c = getCost(value);
    if (cvmap.count(c) == 0 || (cvmap.count(c) > 0 && cvmap[c] < value))
        cvmap[c] = value;
}

string cmp(string &a, string &b)
{
    if (a.size() < b.size())
        return b;
    else if (a.size() > b.size())
        return a;

    return a < b ? b : a;
}

void printans()
{
    sort(dp[n].begin(), dp[n].end(), greater<char>());
    cout << dp[n] << "\n";
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a;
        scanf("%d", &a);
        inputCVMap(a + '0' - 0);
    }

    // Initialize
    for (auto cvp : cvmap)
    {
        dp[cvp.first] += cvp.second;
    }

    for (int i = 1; i <= n; i++)
    {
        if (dp[i] == "")
            continue;

        for (auto cvp : cvmap)
        {
            if (i + cvp.first <= n)
            {
                string v = dp[i];
                v += cvp.second;
                dp[i + cvp.first] = cmp(dp[i + cvp.first], v);
            }
        }
    }

    printans();
    return 0;
}
