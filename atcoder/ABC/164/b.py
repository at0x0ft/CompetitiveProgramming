a, b, c, d = map(int, input().split())
tt = (c + b - 1) // b
at = (a + d - 1) // d
print("Yes" if tt <= at else "No")
