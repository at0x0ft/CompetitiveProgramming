import heapq
n = int(input())
a = list(map(int, input().split()))
l, r = 0, len(a) - 1
ans = 0
while l <= r:
    cost_ls = [(-1 * a[i] * (i - l), i, False) if (i - l > r - i) else (-1 * a[i] * (r - i), i, True) for i in range(len(a))]
    heapq.heapify(cost_ls)
    cost, loc, is_right = heapq.heappop(cost_ls)
    # print(-cost, loc, a[loc], is_right)
    ans -= cost
    a[loc] = 0
    if is_right:
        r -= 1
    else:
        l += 1

print(ans)
