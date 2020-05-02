import heapq

def solve(input: str) -> str:
    px, py, m = tuple(input.split())
    px = int(px)
    py = int(py)

    def char2dir(d: str) -> (int, int):
        if d == "N":
            return (0, 1)
        elif d == "S":
            return (0, -1)
        elif d == "E":
            return (0, 1)
        else:
            return (0, -1)

    def md(c1: tuple) -> int:
        return abs(c1[0]) + abs(c1[1])

    pq = [(md((px, py)), (px, py), m, 0)]
    ops = [(1, 0), (0, 1), (-1, 0), (0, -1), (0, 0)]
    heapq.heapify(pq)
    while len(pq) > 0:
        cost, (px, py), m, step = heapq.heappop(pq)
        print(cost, (px, py), m, step)
        dx, dy = char2dir(m[0])
        px += dx
        py += dy
        step += 1
        m = m[1:]
        for opt in ops:
            npx = px + opt[0]
            npy = py + opt[1]
            if (npx, npy) == (0, 0):
                return int(step)
            cost = md((npx, npy))
            if len(m) * 2 >= cost:
                heapq.heappush(pq, (cost, (npx, npy), m, step))

    return "IMPOSSIBLE"

t = int(input())
[print("Case #{}: {}".format(x + 1, solve(input()))) for x in range(t)]
