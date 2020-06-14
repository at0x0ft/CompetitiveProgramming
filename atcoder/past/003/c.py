import math
a, r, n = map(int, input().split())
print("large" if math.log10(a) + (n - 1) * math.log10(r) > 9 else a * r ** (n - 1))
