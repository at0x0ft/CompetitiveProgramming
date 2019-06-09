#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    string w, p;
    set<string> st;
    bool res = true;
    for (int i = 0; i < n; i++)
    {
        cin >> w;
        if (res && st.count(w) > 0)
        {
            res = false;
        }
        st.insert(w);

        if (i > 0 && p[p.length() - 1] != w[0])
        {
            res = false;
        }
        p = w;
    }

    printf("%s\n", res ? "Yes" : "No");

    return 0;
}
