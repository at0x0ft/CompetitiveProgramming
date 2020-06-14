n = int(input())
dp = [0 for i in range(10 ** 6 + 1)]
a_max = 0
for x in map(int, input().split()):
    a_max = max(a_max, x)
    dp[x] += 1
for i in range(len(dp)):
    if dp[i] == 0:
        continue
    elif dp[i] == 1:
        for j in range(2, (a_max // i + 2)):
            if i * j <= a_max:
                dp[i * j] = 0

print(dp.count(1))
