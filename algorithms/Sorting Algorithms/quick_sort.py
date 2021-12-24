'''
    First, we choose a pivot, then we put the pivot at its correct position using the function partition
    (elements at left are smaller than pivot, elements at right are bigger than pivot)
    then we do the quick sort again to the left array, and right array recursively

    Worst Case Complexity: O(n^2), occurs when the pivot is the smallest or greatest element in array 
    Average Case Complexity: O(n*log(n))
    Best Case Complexity: O(n*log(n)), occurs when the partition process always picks the middle element as pivot.

    Quick Sort in its general form is an in-place sort. So it's better than merge sort in terms of space complexity.

'''

def quick_sort(start, end, arr):
    if start < end:
        p = partition(start, end, arr)
        quick_sort(start, p-1, arr)
        quick_sort(p+1, end, arr)


def partition(start, end, arr):
    pivot_index = start
    pivot = arr[start]
    while start < end:
        while start < len(arr) and arr[start] <= pivot: #means arr[start] is in place relatively to pivot  in the sorted array
            start += 1
        while arr[end] > pivot: #means arr[end] is in place relatively to pivot  in the sorted array
            end -= 1
        if start < end:
            arr[start], arr[end] = arr[end], arr[start]

    arr[end], arr[pivot_index] = arr[pivot_index], arr[end]
    return end #returns the right position of the pivot in sorted array

arr = [4, 0, 1, -6, 9]
quick_sort(0, len(arr)-1, arr)
print(arr)
