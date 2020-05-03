n, m = map(int, input().split())
h = list(map(int, input().split()))
good=[True for _ in range(n)]
for _ in range(m):
    a, b = tuple(map(int, input().split()))
    a -= 1
    b -= 1
    if h[a] > h[b]:
        good[b] = False
    elif h[a] < h[b]:
        good[a] = False
    else:
        good[a] = False
        good[b] = False
count = 0
for i in range(n):
    if good[i]:
        count += 1
print(count)
