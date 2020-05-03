n, k = map(int, input().split())
has = [False for _ in range(n)]
for i in range(k):
    d = int(input())
    a = list(map(int, input().split()))
    for j in range(d):
        has[a[j] - 1] = True
count = 0
for i in range(n):
    if not has[i]:
        count += 1
print(count)
