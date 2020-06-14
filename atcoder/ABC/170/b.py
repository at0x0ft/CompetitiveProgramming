x, y = map(int, input().split())
print("Yes" if y % 2 == 0 and 4 * x >= y and 2 * x <= y else "No")
