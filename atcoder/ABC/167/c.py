n, m, x = map(int, input().split())
b = []
for _ in range(n):
    c, *a = list(map(int, input().split()))
    b.append((c, a))

cost = -1
for bit in range(2 ** n):
    c = 0
    a = [0 for _ in range(m)]
    for i in range(n):
        if ((bit >> i) & 1) == 1:
            c += b[i][0]
            a = [a[j] + b[i][1][j] for j in range(m)]

    j = True
    for i in range(m):
        if x > a[i]:
            j = False
    if j:
        cost = min(cost, c) if cost >= 0 else c

print(cost)
