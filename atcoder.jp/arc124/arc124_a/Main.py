mod = 998244353

n, K = map(int, input().split())
noCard = [1]*n
r = [0]*n

for i in range(K):
    c, k = input().split()
    k = int(k) - 1
    noCard[k] = 0
    if c=="L":
        r[k] += 1
    else:
        r[0] += 1
        r[k] -=1

for i in range(1,n):
    r[i] += r[i-1]

ans = 1

for i,j in zip(r,noCard):
    if j:
        ans *= i
        ans %= mod
print(ans)