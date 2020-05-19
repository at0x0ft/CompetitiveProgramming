a, b, c, k = map(int, input().split())
if a > k:
    print(k)
else:
    k -= a
    if b >= k:
        print(a)
    else:
        k -= b
        print(a - k)
