# This bullshit is here because I suppose, there is some
# bad formatting of input file in test cases
INTS = list()
POSITION = 0
def get_int():
    global INTS
    global POSITION
    while POSITION + 1 > len(INTS):
        INTS = input().split()
        POSITION = 0
    ret = int(INTS[POSITION])
    POSITION += 1
    return ret

cases = get_int()


for i in range(0, cases):
    num = get_int()
    tmp = 5
    fives = 0
    while tmp <= num:
        fives += int(num / tmp)
        tmp *= 5

    print(fives)
