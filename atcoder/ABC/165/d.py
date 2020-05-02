a, b, n = map(int, input().split())
ans = 0
if n >= b:
    ans = int(a * (b - 1) / b) - a * int((b - 1) / b)
else:
    ans = int(a * n / b) - a * int(n / b)
print(ans)
