n, l = map(int, input().split())
x = set(map(int, input().split()))
t = list(map(int, input().split()))

ans = [-1 for _ in range(l + 1)]
ans[0] = 0

def assign_ans(ans, src, dst, val):
    if not (0 <= dst <= l):
        val = (l - src) * t[1] + (t[0] - t[1]) // 2
        dst = l
    ans[dst] = ans[src] + val if ans[dst] < 0 else min(ans[dst], ans[src] + val)
    return

for i in range(l):
    if i in x:
        ans[i] += t[2]
    # else:
    assign_ans(ans, i, i + 1, t[0])
    assign_ans(ans, i, i + 2, t[0] + t[1])
    assign_ans(ans, i, i + 4, t[0] + 3 * t[1])
    # print(ans)

print(ans[l])
