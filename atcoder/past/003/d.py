n = int(input())
s = [input() for _ in range(5)]

def interpret(sl, si):
    if sl[0][si:si + 4] == "..#.":
        return 1
    elif sl[0][si:si + 4] == ".#.#":
        return 4

    if sl[1][si:si + 4] == ".#..":
        if sl[3][si:si + 4] == "...#":
            return 5
        else:
            return 6
    elif sl[1][si:si + 4] == "...#":
        if sl[2][si:si + 4] == "...#":
            return 7
        if sl[3][si:si + 4] == "...#":
            return 3
        else:
            return 2

    if sl[2][si:si + 4] == ".#.#":
        return 0
    elif sl[3][si:si + 4] == ".#.#":
        return 8
    return 9

print("".join([str(interpret(s, i)) for i in range(0, 4 * n, 4)]))
