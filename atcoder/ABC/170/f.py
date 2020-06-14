import heapq

h, w, k = map(int, input().split())
sx, sy, gx, gy = map(int, input().split())
sx -= 1
sy -= 1
gx -= 1
gy -= 1
c = [input() for _ in range(h)]
visited = [[False for _ in range(w)] for _ in range(h)]

def is_in_range(x, y):
    return 0 <= x < h and 0 <= y < w

def calc_cost(x, y):
    return 0 if gy == y and gx == x else (1 if gy == y or gx == x else 2)

pq = [(0, 0, (sx, sy))]
d = [(1, 0), (0, 1), (-1, 0), (0, -1)]
visited[sx][sy] = True
heapq.heapify(pq)

def search():
    while len(pq) != 0:
        _, cost, (cx, cy) = heapq.heappop(pq)
        # print(cost, (cx, cy))
        for dx, dy in d:
            for kk in range(1, k + 1):
                nx, ny = cx + dx * kk, cy + dy * kk
                if not is_in_range(nx, ny) or c[nx][ny] == '@' or visited[nx][ny]:
                    break
                # if c[nx][ny] == '@':
                #     break
                # # print((nx, ny))
                # if not visited[nx][ny]:
                visited[nx][ny] = True
                if c[nx][ny] == '.':
                    if ny == gy and nx == gx:
                        return cost + 1
                    heapq.heappush(pq, (calc_cost(nx, ny) + cost + 1, cost + 1, (nx, ny)))

    return -1

print(search())
