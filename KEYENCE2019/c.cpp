#include <bits/stdc++.h>

using namespace std;

int solve(vector<long long int> &pos, const int posCnt, long long int neg, const int negCnt)
{
    if (neg >= 0)
        return 0;
    sort(pos.begin(), pos.end(), greater<long long int>());
    for (int i = 0; i < posCnt; i++)
    {
        neg += pos[i];
        if (neg >= 0)
            return i + 1 + negCnt;
    }
    return -1;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<long long int> dif(n), pos(n);
    long long int neg = 0;
    int posCnt = 0, negCnt = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &dif[i]);
    }
    for (int i = 0; i < n; i++)
    {
        long long int buf;
        scanf("%lld", &buf);
        buf = dif[i] - buf;
        if (buf > 0)
            pos[posCnt++] = buf;
        else
        {
            neg += buf;
            negCnt++;
        }
        dif[i] = buf;
    }

    pos.resize(posCnt);
    printf("%d\n", solve(pos, posCnt, neg, negCnt));

    return 0;
}