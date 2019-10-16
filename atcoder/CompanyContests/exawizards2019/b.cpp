#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    string cs;
    cin >> cs;
    int rn = 0, bn = 0;
    for (int i = 0; i < n; i++)
    {
        if (cs[i] == 'R')
            rn++;
        else
            bn++;
    }
    printf("%s\n", rn > bn ? "Yes" : "No");

    return 0;
}
