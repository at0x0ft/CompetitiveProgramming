#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    long long int C;

    scanf("%d %lld", &N, &C);

    vector<long long int> x(N + 1), v(N + 1);
    for (int i = 1; i <= N; i++)
    {
        scanf("%lld %lld", &(x[i]), &(v[i]));
    }
    x[0] = 0;
    v[0] = 0;

    long long int ans = 0, ncnd, bcnd, ncst, bcst;
    int now = 0, next = 1, back = N;
    while (true)
    {
        fprintf(stderr, "debug print : now@%lld\n", x[now]); // 4debug

        if (now < next)
        {
            ncst = x[next] - x[now];
            bcst = x[now] + C - x[back];
        }
        else if (now > back)
        {
            ncst = x[next] + C - x[now];
            bcst = x[now] - x[back];
        }
        ncnd = v[next] - ncst;
        bcnd = v[back] - bcst;
        if (ncnd < 0 && bcnd < 0)
        {
            fprintf(stderr, "debug print : cancel\n"); // 4debug
            break;
        }
        else if (ncnd < 0 || (bcnd > 0 && ncnd > 0 && bcst < ncst))
        {
            now = back;
            ans += bcnd;
            back--;
            fprintf(stderr, "debug print : back\n"); // 4debug
        }
        else if (bcnd < 0 || (bcnd > 0 && ncnd > 0 && ncnd < bcst))
        {
            now = next;
            ans += ncnd;
            next++;
            fprintf(stderr, "debug print : next\n"); // 4debug
        }
        if (next > back)
        {
            fprintf(stderr, "debug print : end\n"); // 4debug
            break;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
