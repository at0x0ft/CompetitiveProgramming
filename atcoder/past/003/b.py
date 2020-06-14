n, m, q = map(int, input().split())

ls = [[False for _ in range(n)] for _ in range(m)]
cnt = [0 for _ in range(m)]

def exec_query(s):
    s = s.split()
    # print(s)
    if len(s) == 2:
        _, x = map(int, s)
        x -= 1
        ans = 0
        for i in range(m):
            if ls[i][x]:
                ans += n - cnt[i]
        print(ans)
    else:
        _, x, y = map(int, s)
        x -= 1
        y -= 1
        ls[y][x] = True
        cnt[y] += 1
    # print(ls)
    # print(cnt)
    return

[exec_query(input()) for _ in range(q)]
