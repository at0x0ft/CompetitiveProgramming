#include <bits/stdc++.h>

using namespace std;

int minCyc(const int s, const int i, set<int> &st)
{
    if (st.count(s) > 0)
        return i;
    st.insert(s);
    if (s % 2 == 0)
        return minCyc(s / 2, i + 1, st);
    else
        return minCyc(3 * s + 1, i + 1, st);
}

int main()
{
    int s;

    scanf("%d", &s);

    set<int> st;
    printf("%d\n", minCyc(s, 1, st));

    return 0;
}