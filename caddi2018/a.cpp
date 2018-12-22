#include <bits/stdc++.h>

using namespace std;

int main()
{
    string n;
    cin >> n;

    int cnt = 0;
    for (int i = 0; i < n.size(); i++)
    {
        if (n[i] == '2')
            cnt++;
    }

    printf("%d\n", cnt);

    return 0;
}