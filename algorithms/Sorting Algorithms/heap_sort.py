'''
    Heap sort works by visualizing the elements of the array 
    as a special kind of complete binary tree called a max-heap.

    A very good explanation of heap sort:
        https://www.programiz.com/dsa/heap-sort

    Time Complexity: O( n*log(n) ) :
        - Complexity of heapify_subtree = O(log(n))
        - Complexity of building the max-heap = O(n)
'''

def heapify_subtree(arr, n, i):
    largest = i # i is the index of root
    l = 2 * i + 1
    r = 2 * i + 2
    if l < n and arr[l] > arr[largest]:
        largest = l
    if r < n and arr[r] > arr[largest]:
        largest = r
    if largest != i:
        arr[largest] , arr[i] = arr[i], arr[largest]
        heapify_subtree(arr, n, largest)

def heap_sort(arr):
    n = len(arr)
    for i in range(n//2 - 1, -1, -1):
        heapify_subtree(arr, n, i)
    for i in range(n-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify_subtree(arr, i, 0)

arr = [10, 0, 1, -20, 5, 4]
heap_sort(arr)
print(arr)