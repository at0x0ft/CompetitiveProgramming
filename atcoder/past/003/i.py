n = int(input())
idx = [i for i in range(n)]
jdx = [j for j in range(n)]
# t = [[n * i + j for j in range(n)] for i in range(n)]
# print(t)
transposed = False
qs = int(input())

def exec_query(q):
    if q == "3":
        global transposed
        transposed = not transposed
        # print(transposed)
        return

    def swap_dx(dx, a, b):
        # print(dx, a, b)
        dx[a], dx[b] = dx[b], dx[a]
        # print(dx)
        return

    def access(a, b):
        return n * idx[a] + jdx[b] if not transposed else n * idx[b] + jdx[a]

    qn, a, b = map(int, q.split())
    a -= 1
    b -= 1
    if qn == 1:
        swap_dx(idx if not transposed else jdx, a, b)
    elif qn == 2:
        swap_dx(jdx if not transposed else idx, a, b)
    else:
        # print(a, b, (idx[a], idx[b]) if not transposed else (idx[b], jdx[a]))
        print(access(a, b))
    return

[exec_query(input()) for _ in range(qs)]
