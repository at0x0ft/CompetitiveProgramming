n = list(map(int, input().split()))
n.sort()
print("YES" if n[0] == 5 and n[1] == 5 and n[2] == 7 else "NO")
