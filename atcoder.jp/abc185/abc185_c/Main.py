from math import factorial

n = int(input())
n = n-1
print(factorial(n) // factorial(11) // factorial(n - 11))