n, m, q = map(int, input().split())
MAX_N = 200
adj = [[False for _ in range(MAX_N)] for _ in range(MAX_N)]
for _ in range(m):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    adj[u][v] = True
    adj[v][u] = True
c = list(map(int, input().split()))

def exec_query(s):
    s = s.split()
    if len(s) == 2:
        _, x = map(int, s)
        x -= 1
        print(c[x])
        for i in range(len(adj)):
            if adj[x][i]:
                c[i] = c[x]
    else:
        _, x, y = map(int, s)
        x -= 1
        print(c[x])
        c[x] = y
    return

[exec_query(input()) for _ in range(q)]
