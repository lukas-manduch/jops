import sys
import math

def comp(n):
    res = (n + 1) * int(n/2)
    if n%2 == 1:
        res += int(n/2)+1
    return int(n*n/2 + n/2) + 1


case = int(input())
for i in range(0, case):
    n = int(input())
    odh = int(math.sqrt(n*2)) - 1
    while comp(odh) < n:
        odh += 1
    print(odh)
