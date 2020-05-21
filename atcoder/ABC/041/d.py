import math
h, w, a, b = map(int, input().split())
MOD = 10 ** 9 + 7
print((math.factorial(h + w) // (math.factorial(h) * math.factorial(w)) - math.factorial(a + b) // (math.factorial(a) * math.factorial(b))) % MOD)
