'''
    It divides the input array into two halves,
    calls itself for the two halves,
    and then merges the two sorted halves.

    Time Complexity: O( n*log(n) )
'''

def merge_sort(arr):
    n = len(arr)
    if n > 1:
        q =  n//2
        L = arr[:q]
        R = arr[q:]
        merge_sort(L)
        merge_sort(R)
        merge(arr, L, R)

def merge(arr, L, R):
    i = j = k = 0
    while i < len(L) and j < len(R):
        if L[i] < R[j]:
            arr[k] = L[i]
            i += 1
            k += 1
        else:
            arr[k] = R[i]
            j += 1
            k += 1
    
    while j < len(R):
        arr[k] = R[j]
        j += 1
        k += 1
    
    while i < len(L):
        arr[k] = L[i]
        i += 1
        k += 1

arr = [4, 0, 1, -6, 9]
merge_sort(arr)
print(arr)