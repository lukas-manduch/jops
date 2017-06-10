import sys

def make_pali(str1):
    str2 = list()
    skip = False
    mid_found = 0
    if len(str1) %2 != 1:
        mid_found = -1
        
    for i in range(0, len(str1)):
        if skip:
            skip = False
            continue
        if i == len(str1) - 1 and not mid_found:
                mid_found = ord(str1[i])
                continue
        if str1[i] == str1[i+1]:
            str2.append(str1[i])
            skip = True
            continue
        if mid_found:
            return 'NO LUCK'
        mid_found = ord(str1[i])
    if mid_found > 0:
        return ''.join(str2) + chr(mid_found) + ''.join(str2)[::-1]
    return ''.join(str2) + ''.join(str2)[::-1]
    
        
        

def pali(str1, str2):
    i1 = 0
    i2 = 0
    diff = str()
    for i1 in range(0, len(str1)):
        if i2 == len(str2) or str1[i1] != str2[i2]:
            diff += str1[i1]
        else:
            i2 += 1
    if i2 != len(str2):
        return 'NO LUCK'
    return make_pali(diff)

total = int(input())
for i in range(0, total):
    str1 = sorted(sys.stdin.readline().lower())
    str2 = sorted(sys.stdin.readline().lower())
    str1 = ''.join([i for i in str1 if i.isalpha()])
    str2 = ''.join([i for i in str2 if i.isalpha()])    

    # print("LENS ARE " + str(len(str1)) + " " + str(len(str2)))
    # print(str1)
    # print(str2)
    if len(str1)!=len(str2):
        if len(str1) > len(str2):
            res = pali(str1, str2)
        else:
            res = pali(str2, str1)
    else:
        if str1==str2:
            res = 'YES'
        else:
            res = 'NO LUCK'
    print(res)
exit(0)
