'''
    Sort an array by repeatedly finding the minimum element in the unsorted array
        and place it at the beginning.
    Time Complexity: O(n^2)
'''


def selection_sort(arr):
    swaps = 0
    n = len(arr)
    for i in range(n):
        min_index = i
        for j in range(i+1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]
        swaps += 1
    return (arr, swaps)

arr = [7, 15, 12, 3]
print(selection_sort(arr))
