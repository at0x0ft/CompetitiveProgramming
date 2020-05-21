# import itertools

# n, k = map(int, input().split())
# d = [i for i in range(10)]
# [d.remove(int(x)) for x in input().split()]
# n_len = len(str(n))

# ans = -1
# for x in itertools.product(d, repeat=n_len):
#     v = int("".join([str(i) for i in list(x)]))
#     # print(v)
#     if v >= n:
#         if ans < 0 or ans > v:
#             ans = v

# if ans < 0:
#     for x in itertools.product(d, repeat=n_len+1):
#         v = int("".join([str(i) for i in list(x)]))
#         # print(v)
#         if v >= n:
#             if ans < 0 or ans > v:
#                 ans = v

# print(ans)

n, k = map(int, input().split())
d = [i for i in range(10)]
[d.remove(int(x)) for x in input().split()]
n_len = len(str(n))

def rec_define_digit(s):
    v = int(s)
    # print(s)
    if v >= n:
        return v
    ans = 999999
    if len(s) >= n_len + 2:
        return ans
    for i in d:
        ans = min(rec_define_digit(s + str(i)), ans)
    return ans

print(rec_define_digit("0"))
