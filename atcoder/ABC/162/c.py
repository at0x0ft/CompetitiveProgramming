MAX_K: int = 200

gt = [[0 for _ in range(MAX_K + 1)] for _ in range(MAX_K + 1)]

def gcd(x: int, y: int) -> int:
    if gt[x][y] > 0:
        return gt[x][y]
    ret: int = 0
    if x < y:
        ret = gcd(y, x)
    elif y == 0:
        ret = x
    elif y == 1:
        ret = 1
    else:
        ret = gcd(y, x % y)
    gt[x][y] = ret
    # print(f"gcd({x}, {y}) = {ret}")
    return ret

k = int(input())
print(sum([gcd(gcd(i + 1, j + 1), l + 1) for i in range(k) for j in range(k) for l in range(k)]))
