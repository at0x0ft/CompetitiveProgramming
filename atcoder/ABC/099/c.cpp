#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;

    int b[] = { 46656, 7776, 1296, 216, 36, 6};
    int c[] = { 59049, 6561, 729, 81, 9, 1};

    scanf("%d", &N);

    int ans = INT_MAX, ntmp, btmp, ctmp, ktmp;

    for(int k = 0; k <= N; k += 6)
    {
        ntmp = N - k;
        ktmp = k;
        btmp = 0;
        ctmp = 0;

        for(int i = 0; i < 6; i++)
        {
            btmp += ktmp / b[i];
            ktmp %= b[i];
        }
        for(int i = 0; i < 6; i++)
        {
            ctmp += ntmp / c[i];
            ntmp %= c[i];
        }

        if(btmp + ctmp < ans) {
            ans = btmp + ctmp;
        }
    }

    printf("%d\n", ans);

    return 0;
}
