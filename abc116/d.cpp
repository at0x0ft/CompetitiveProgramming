#include <bits/stdc++.h>

using namespace std;

long long int simpleMaxSum(vector<vector<int>> &td, vector<bool> &slt, const int k)
{
    int cnt = 0;
    // for (int i = 0; i < ; i++)
    {
    }
}

long long int dp(vector<vector<int>> &td, vector<bool> &slt, const int k)
{
}

bool pairGreaterSecondComparator(pair<int, int> l, pair<int, int> r)
{
    return l.second > r.second;
}

bool tdComparator(map<int, int, greater<int>> l, map<int, int, greater<int>> r)
{
    return l.begin()->first > r.begin()->first;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int t, d;
    vector<map<int, int, greater<int>>> td(n);
    vector<int> tcnt(n, 0);
    vector<pair<int, int>> flatTD(n);
    vector<bool> select(n, false);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &t, &d);
        td[t - 1].insert(make_pair(d, i));
        flatTD[i] = pair<int, int>(t - 1, d);
    }

    sort(flatTD.begin(), flatTD.end(), pairGreaterSecondComparator);
    sort(td.begin(), td.end(), tdComparator);

    for (int i = 0; i < n; i++)
    {
        printf("@%d = %d\n", i + 1, td[i].begin()->first);
        printf("flatTD[%d] = (t = %d, d = %d)\n", i, flatTD[i].first, flatTD[i].second);
    }

    return 0;
}
