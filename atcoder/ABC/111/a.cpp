#include <bits/stdc++.h>

using namespace std;

inline char convert(const char c)
{
    switch (c)
    {
    case '1':
        return '9';
    case '9':
        return '1';
    default:
        return '0';
    }
}

int main()
{
    char x[3];
    scanf("%c%c%c", &x[0], &x[1], &x[2]);

    printf("%c%c%c\n", convert(x[0]), convert(x[1]), convert(x[2]));

    return 0;
}
