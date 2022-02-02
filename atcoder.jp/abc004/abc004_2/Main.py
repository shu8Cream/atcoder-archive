c = [list(input().split()) for _ in range(4)]
ans = [['' for i in range(4)] for j in range(4)]
for i in range(4):
    for j in range(4):
        ans[3-i][3-j] = c[i][j]

for row in ans:
    print(*row)