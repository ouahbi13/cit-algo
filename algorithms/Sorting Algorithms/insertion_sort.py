'''
    The array is virtually split into a sorted and an unsorted part.
    Values from the unsorted part are picked and placed at the correct position in the sorted part.
    
    Time Complexity: O(n^2)
'''

def insertion_sort(arr):
    n = len(arr)
    for i in range(1, n):
        element = arr[i]
        j = i-1
        while j >= 0 and arr[j] > element:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = element
    return arr

arr = [4, 0, 1, -6, 9]
print(insertion_sort(arr))

