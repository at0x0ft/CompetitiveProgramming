n, k = map(int, input().split())
a = [int(t) - 1 for t in input().split()]

loc = 0
visited_bkt = [-1 for _ in range(2 * 10 ** 5 + 1)]
count = 0
loop_len = -1
while True:
    visited_bkt[loc + 1] = count
    loc = a[loc]
    count += 1
    if visited_bkt[loc + 1] >= 0:
        loop_len = count - visited_bkt[loc + 1]
        break
start_len = count - loop_len
print(visited_bkt.index(start_len + (k - start_len) % loop_len) if k >= count else visited_bkt.index(k))
