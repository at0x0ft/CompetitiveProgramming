import queue
n, gx, gy = map(int, input().split())
obs = [tuple(map(int, input().split())) for _ in range(n)]
visited = set()
que = queue.Queue()
que.put((0, (0, 0)))
visited.add((0, 0))
[visited.add((x, y)) for x, y in obs]
d6 = [(1, 1), (0, 1), (-1, 1), (1, 0), (-1, 0), (0, -1)]
ans = -1
while not que.empty():
    step, (x, y) = que.get()
    # print(step, x, y)
    for dx, dy in d6:
        if ((x + dx, y + dy) in visited) or (not (-250 <= (x + dx) <= 250 and -250 <= (y + dy) <= 250)):
            continue
        elif (x + dx) == gx and (y + dy) == gy:
            ans = step + 1
            break
        que.put((step + 1, (x + dx, y + dy)))
        visited.add((x + dx, y + dy))
    if ans > 0:
        break

print(ans)
