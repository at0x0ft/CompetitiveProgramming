import math

x = int(input())
i = 1
v = 100
while True:
    v = int(1.01 * v)
    if v >= x:
        break
    i += 1
print(i)
