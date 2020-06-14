s = input()
t = input()
print("same" if s == t else ("case-insensitive" if s.lower() == t.lower() else "different"))
