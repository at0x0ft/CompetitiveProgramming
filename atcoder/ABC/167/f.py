n = int(input())
a = list(map(int, input().split()))
if n % 2 != 0:
    a.remove(min(a))
a_sum = sum(a)
ea_sum = sum([a[i] for i in range((n // 2) * 2) if i % 2 == 0])
print(f"{a_sum}, {ea_sum}, {a_sum - ea_sum}")
ans = max(a_sum - ea_sum, ea_sum)
print(ans)
