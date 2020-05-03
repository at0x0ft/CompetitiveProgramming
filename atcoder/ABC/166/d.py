x = int(input())

def search(x: int) -> (int, int):
    for a in range(-1000, 1001):
        for b in range(-1000, 1001):
            if a ** 5 - b ** 5 == x:
                return (a, b)
    return (-2000, -2000)

a, b = search(x)
print(f"{a} {b}")
