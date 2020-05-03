n, m, q = map(int, input().split())
req = []
[req.append(tuple(map(int, input().split()))) for _ in range(q)]
a = [0 for _ in range(n)]

def check():
    res = 0
    for i in range(q):
        ra, rb, rc, rd = req[i]
        if a[rb - 1] - a[ra - 1] == rc:
            res += rd
    return res

def set_a(idx: int, au: int):
    ans = 0
    for i in range(au, m + 1):
        a[idx] = i
        if idx + 1 < n:
            ans = max(set_a(idx + 1, i), ans)
        else:
            ans = max(check(), ans)
    return ans

print(set_a(0, 1))
