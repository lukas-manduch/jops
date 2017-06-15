import sys

while True:
    i = int(input())
    if i == 0:
        exit(0)
    status = 0
    summ = 0
    lst = list(input().split())
    for i in lst:
        i = int(i)
        status += i
        summ += abs(status)
    print(summ)    
