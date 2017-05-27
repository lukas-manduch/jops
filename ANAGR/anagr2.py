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


dictt = dict()



total = int(input())
for i in range(0, total):
    str1 = sys.stdin.readline()
    str2 = sys.stdin.readline()
    str1 = ''.join([i.lower() for i in str1 if i.isalpha()])
    str2 = ''.join([i.lower() for i in str2 if i.isalpha()])    

    dict1 = {chr(key) : 0 for key in range(ord('a'), ord('z') + 1 )}
    dict2 = {chr(key) : 0 for key in range(ord('a'), ord('z') + 1 )}
    if len(str2) > len(str1):
        str_tmp = str1
        str1 = str2
        str2 = str_tmp
    for l in str1:
        dict1[l] += 1
    for l in str2:
        dict2[l] += 1


    odd = 0
    odd_char = str()
    out_str = str()
    for key in dict1:
        res = dict1[key] - dict2[key]
        if res < 0:
            odd = 3 # Error
        if res % 2 == 1: # this is middle
            odd += 1
            odd_char = key

        out_str += ''.ljust(int(res/2), key)
    if odd > 1:
        print('NO LUCK')
        continue
    if odd == 1:
        print(''.join(out_str) + odd_char + ''.join(out_str)[::-1])
    if len(out_str) and not odd:
        print(''.join(out_str) + ''.join(out_str)[::-1])
    else:
        print('YES')

exit(0)
