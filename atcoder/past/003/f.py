n = int(input())
a = [input() for _ in range(n)]

ans = []
for i in range(0, (n // 2 + 1) if n % 2 == 1 else n // 2):
    cnd = list(set(a[i]) & set(a[n - i - 1]))
    if cnd == []:
        ans.clear()
        break
    ans.append(cnd[0])
    # print(cnd[0])

if len(ans) == 0:
    print(-1)
else:
    # print("".join(ans))
    # print("".join(reversed(ans)))
    # print("".join(reversed(ans))[n % 2 : len(ans)], n % 2, len(ans))
    print("".join(ans) + "".join(reversed(ans))[n % 2 : len(ans)])
