#include <bits/stdc++.h>

#define MAX_N 200000

using namespace std;

bool operator<(const pair<int, int> left, const pair<int, int> right)
{
    return left.first < right.second;
}

bool operator>(const pair<int, int> left, const pair<int, int> right)
{
    return left.first > right.second;
}

int main()
{
    int N, a, b, buf;
    set<int> low;

    scanf("%d", &N);
    vector< pair<int, int> > A(N);
    for (int i = 0; i <= N - 1; i++)
    {
        scanf("%d", &buf);
        A[i].first = buf;
        A[i].second = i;
    }

    for (int i = 0; i <= N - 1; i++)
    {
        scanf("%d", &buf);
        vector<pair<int, int>> A(N - 1);
        A[i].first = buf;
        A[i].second = i;
    }
    stable_sort(A.begin(), A.end());

    for (int i = 0; i < N / 2; i++)
    {
        low.insert(A[i].second);
    }

    for (int i = 0; i <= N - 1; i++)
    {
        printf("%d\n", low.count(A[i].second) == 0 ? A[N / 2 - 1].first : A[N / 2].first);
    }

    return 0;
}
