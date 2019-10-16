#include <bits/stdc++.h>

using namespace std;

#define MAX_N 10000

int count2Div(int a, int count)
{
    if(a % 2 == 0) return count2Div(a / 2, count + 1);
    else return count;
}

int main()
{
    int N;

    scanf("%d", &N);
    int buf, ans = 0;
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &buf);
        ans += count2Div(buf, 0);
    }

    printf("%d\n", ans);

    return 0;
}
