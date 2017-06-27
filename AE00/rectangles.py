import math

num = int(input())

def get_count(num):
    if num < 2:
        return num
    divs = 1
    end_num = math.sqrt(num) + 1 # Handles zero case
    start_num = 2
    while start_num < int(end_num):
#        print(str(start_num) + " " + str(end_num))
        if num%start_num == 0: # We found divisor
            divs += 1
            end_num = num / start_num
        start_num += 1
#    print(str(num) + " has " + str(divs))    
    return divs

sum_divs = 0
for i in range(1, num+1):
    sum_divs += get_count(i)
print(sum_divs)
