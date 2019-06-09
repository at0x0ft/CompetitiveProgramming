#include <bits/stdc++.h>

using namespace std;

#define MAX_C 30
#define MAX_N 500

int main()
{
    int N, C;
    int D[MAX_C + 1][MAX_C + 1], board[MAX_N + 1][MAX_N + 1], group[3][MAX_C + 1];
    memset(group[0], 0);
    memset(group[1], 0);
    memset(group[2], 0);

    scanf("%d %d", &N, &C);
    int fst = (N + 1) % 3;

    for(int i = 1; i < C + 1; i++)
    {
        for(int j = 1; j < C + 1; j++)
        {
            scanf("%d", &(D[i][j]));
        }
    }

    int buf;
    for(int i = 1; i < N + 1; i++)
    {
        for(int j = 1; j < N + 1; j++)
        {
            scanf("%d", &buf);
            group[(i + j) % 3][buf]++;
        }
    }

    int max = -1, idx;
    for(int i = 1; i <= N; i++)
    {
        if(max < group[fst][i])
        {
            max = group[fst][i];
            idx = i;
        }
    }

    int ans = 0;
    for(int i = 0; i <= N; i++)
    {
        if(i != idx)
        {
            ans += group[fst][i] * D[i][idx];
        }
    }

    


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
