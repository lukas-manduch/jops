while True:
    arr = input().split()
    a = int(arr[0])
    b = int(arr[1])
    c = int(arr[2])
    if a == 0 and b == 0 and c == 0:
        exit(0)
    if (b-a) == (c-b):
        print("AP " + str(int(c + c-b)))
    else:
        print("GP " + str(int(c*(b/a))))
