n = int(input())
a = list(map(int, input().split()))
ans = [0 for _ in range(n)]
for i in range(len(a)):
    ans[a[i] - 1] += 1

[print(n) for n in ans]
