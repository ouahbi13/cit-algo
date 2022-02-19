'''
    Explanation: https://www.geeksforgeeks.org/jump-search/ 
'''
import math

def jump_search(arr, x):
    n = len(arr)
    m = int(math.sqrt(n))

    previous = 0

    while arr[min(n-1,m)] < x:
        previous = m
        m += int(math.sqrt(n))
        if previous >= n:
            return -1
    

    for i in range(previous, min(n,m)):
        if arr[i] == x:
            return i

    return -1

arr = [1, 2, 3, 6, 10, 23]
print(jump_search(arr, 23))