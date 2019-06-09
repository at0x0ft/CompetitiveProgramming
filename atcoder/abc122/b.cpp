#include <bits/stdc++.h>

using namespace std;

inline bool isOK(const char c)
{
    return c == 'A' || c == 'T' || c == 'C' || c == 'G';
}

int main()
{
    string s;
    cin >> s;

    int ans = 0, slen = s.length();
    for (int i = 0; i < slen; i++)
    {
        for (int j = i; j < slen; j++)
        {
            if (isOK(s[j]))
                ans = max(ans, j - i + 1);
            else
                break;
        }
    }

    printf("%d\n", ans);

    return 0;
}
