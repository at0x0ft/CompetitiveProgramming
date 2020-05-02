n, m = map(int, input().split())
a = list(map(int, input().split()))
sum_a = sum(a)
print(n - sum_a if n - sum_a >= 0 else -1)
