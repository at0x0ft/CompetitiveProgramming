def solve(tp: tuple) -> (int, list):
    r, s = tp
    deck = [(i, j) for j in range(s) for i in range(r)]
    ops = []
    r -= 1
    s_count = s
    while r >= 0:
        opb = len(deck)
        for loc in reversed(range(len(deck))):
            if opb == len(deck):
                if deck[loc][0] == r:
                    s_count -= 1
                    if s_count == 0:
                        s_count = s
                        r -= 1
                else:
                    opb = loc
            else:
                if deck[loc][0] == r:
                    # print(loc, opb)
                    # print(deck)
                    deck = deck[loc + 1 : opb + 1] + deck[0 : loc + 1]
                    # print(deck)
                    ops.append((loc + 1, opb - loc))
                    break

    return len(ops), ops

t = int(input())
for x in range(t):
    y, ops = solve(tuple(map(int, input().split())))
    print("Case #{}: {}".format(x + 1, y))
    [print("{} {}".format(op[0], op[1])) for op in ops]
