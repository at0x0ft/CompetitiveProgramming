n, m, q = map(int, input().split())
req = []
[req.append(tuple(map(int, input().split())), True) for _ in range(q)]
req.sort()
i = 0
while True:
    r, t = req[i]
    if t:

    i += 1
print(req)
