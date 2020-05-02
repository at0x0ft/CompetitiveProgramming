def solve(tp: tuple) -> str:
    def is_valid_cor(x: int, y: int) -> bool:
        return (x % 2 == 0 and y % 2 == 1) or (x % 2 == 1 and y % 2 == 0)

    tx, ty = tp
    if not is_valid_cor(tx, ty):
        return "IMPOSSIBLE"

    ans = ""
    while True:
        # print(f"now = ({tx},{ty}), ans = {ans}")
        if tx % 2 == 1:
            nx, ny = (tx - 1) // 2, ty // 2
            if nx == 0 and ny == 0:
                ans += "E"
                break
            elif nx + 1 == 0 and ny == 0:
                ans += "W"
                break
            if is_valid_cor(nx, ny):
                tx, ty = nx, ny
                ans += "E"
            else:
                tx, ty = nx + 1, ny
                ans += "W"
        elif ty % 2 == 1:
            nx, ny = tx // 2, (ty - 1) // 2
            if nx == 0 and ny == 0:
                ans += "N"
                break
            elif nx == 0 and ny + 1 == 0:
                ans += "S"
                break
            if is_valid_cor(nx, ny):
                tx, ty = nx, ny
                ans += "N"
            else:
                tx, ty = nx, ny + 1
                ans += "S"
        else:
            return "IMPOSSIBLE"
    return ans

t = int(input())
[print("Case #{}: {}".format(x + 1, solve(tuple(map(int, input().split()))))) for x in range(t)]
