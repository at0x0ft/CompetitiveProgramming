n = int(input())
a = list(map(int, input().split()))
s, d = [], []
for i in range(n):
    s.append(a[i] + i + 1)
    d.append(i + 1 - a[i])
cnt = dict()
ans = 0
for i in reversed(range(n)):
    if i < n - 1:
        if s[i] in cnt:
            ans += cnt[s[i]]
    if d[i] in cnt:
        cnt[d[i]] += 1
    else:
        cnt[d[i]] = 1
print(ans)
