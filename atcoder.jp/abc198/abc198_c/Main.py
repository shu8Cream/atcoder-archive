r,x,y = map(int,input().split())
ng = -1
ok = 1001001001001001

while ok-ng>1:
  mid = (ok + ng) // 2;
  dist = x*x+y*y
  if dist<=mid*mid*r*r:
    ok = mid
  else:
    ng = mid
if ok == 1 and dist!=ok*ok*r*r:
  ok = 2
print(ok)