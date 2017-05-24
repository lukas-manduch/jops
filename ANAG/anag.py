import sys

total = int(input())
for i in range(0, total):
    str = sys.stdin.readline()
    str = str.split()
    str1 = sorted(str[0])
    str2 = sorted(str[1])
    if str1==str2:
        print('YES')
    else:
        print('NO')
