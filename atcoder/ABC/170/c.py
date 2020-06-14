from functools import cmp_to_key

x, n = map(int, input().split())
p = set(map(int, input().split()))
for d in range(100):
    if (x - d) >= -101 and (x - d) not in p:
        print(x - d)
        break
    elif (x + d) <= 101 and (x + d) not in p:
        print(x + d)
        break
