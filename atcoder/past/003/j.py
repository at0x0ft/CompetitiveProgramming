import bisect
n, m = map(int, input().split())
a = list(map(int, input().split()))

dl = 0
prev = 10 ** 9 + 1
h = [0 for _ in range(n)]
for i in a:
    idx = bisect.bisect_left(h, i) - 1
    # print(idx)
    if idx >= 0:
        h[idx] = i
    else:
        idx = n + 1
    # print(h)
    print(n - idx)
    # dl = dl + 1 if prev > i else 1
    # prev = i
    # print(dl if dl <= n else -1)
    # ans.append(dl if dl <= n else -1)

