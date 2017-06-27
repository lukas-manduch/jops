
def get_answer(arr : list):
    un_sum = 0
    unique = 1 if len(arr) else 0
    for j in range(0, len(arr) - 1):
        if (un_sum + arr[j]) < arr[j+1]:
            un_sum += arr[j]
            unique += 1
    return unique


INTS = list()
POSITION = 0

# This bullshit is here because I suppose, there is some
# bad formatting of input file in test cases
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
    count = get_int()
    arr = list()
    is_sorted = True
    max_seen = 0
    
    for j in range(0, count): # Load int
        some_int = get_int()
        if some_int < max_seen: # Decide if arr is sorted
            is_sorted = False
        max_seen = some_int
        arr.append(some_int)

    if not is_sorted:
        arr = sorted(arr)
        
    print("Case #" + str(i+1) + ": " + str(get_answer(arr)))
