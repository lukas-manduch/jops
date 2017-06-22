i = int(input())
while i > 0:
    i -= 1
    arr = input().split()
    print(int(str(int(arr[0][::-1]) + int(arr[1][::-1]))[::-1]))
