n = int(input())
a = [int(input()) for i in range(n)]
c = []
for e in a:
    c.append(e)
s = set(c)
s.remove(max(s))
print(max(s))
