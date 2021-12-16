'''
    Given an array of n numbers, calculate the maximum subarray sum,
    i.e., the largest possible sum of a sequence of consecutive values in the array.
'''

def optimal_max_subarry(L):
    max_sum = 0
    s = 0
    for i in range(len(L)):
        s = max(L[i], L[i]+s)
        max_sum = max(max_sum, s)
    return max_sum

L = [-1, 2, 4, -3, 5, 2, -5, 2]

print(optimal_max_subarry(L))