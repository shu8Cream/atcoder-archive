n = int(input())

ans = 0
mod = 998244353

p = 1
while p*p<=n:
    ans += (n//p-p+2)//2
    ans %= mod
    p+=1

print(ans)