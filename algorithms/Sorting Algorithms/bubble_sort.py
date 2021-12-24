'''
    Repeatedly swap the adjacent elements that are in the wrong order.
    Time Complexity: O(n^2)
'''

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr

arr = [4, 0, 1, -6, 9]
print(bubble_sort(arr))
