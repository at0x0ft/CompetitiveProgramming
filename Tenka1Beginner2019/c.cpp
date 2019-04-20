#include <bits/stdc++.h>

using namespace std;
struct CinInit
{
    CinInit()
    {
        cin.tie(0);
        ios::sync_with_stdio(0);
        cout << fixed << setprecision(20);
    };
} CinInit;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int b = 0, w = 0;

    int i = 0;
    while (s[i] == '.')
        i++;
    int j = n - 1;
    while (s[j] == '#')
        j--;

    cerr << "[debug] : i = " << i << "\n"; // 4debug
    cerr << "[debug] : j = " << j << "\n"; // 4debug
    for (; i <= j; i++)
    {
        if (s[i] == '#')
        {
            b++;
        }
        else
            w++;
    }

    cerr << "[debug] : b = " << b << "\n"; // 4debug
    cerr << "[debug] : w = " << w << "\n"; // 4debug
    cout << min(b, w) << "\n";

    return 0;
}
