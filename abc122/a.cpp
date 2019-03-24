#include <bits/stdc++.h>

using namespace std;

int main()
{
    char b;
    scanf("%c", &b);
    char ans;
    switch (b)
    {
    case 'A':
        ans = 'T';
        break;
    case 'T':
        ans = 'A';
        break;
    case 'C':
        ans = 'G';
        break;
    case 'G':
        ans = 'C';
        break;
    default:
        break;
    }

    printf("%c\n", ans);

    return 0;
}
