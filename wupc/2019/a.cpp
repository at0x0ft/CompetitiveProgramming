#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    for (int i = s.length() - 1; i > 0; i--)
    {
        if (s[i - 1] == 'W' && s[i] == 'A')
        {
            s[i - 1] = 'A';
            s[i] = 'C';
        }
    }

    cout << s << "\n";

    return 0;
}
