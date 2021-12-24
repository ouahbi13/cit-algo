'''
    1. Count the number of occurrences of each element and insert the counts in the count array.
    2. Do a cumulative sum of the count array
    3. Now the value of element in index i of the count array is the position of the element in the sorted array + 1

    Time Complexity: O(n)
    Space Complexity: O(n+m)

    - Count Sort becomes impractical when the range is very big compared to n.
'''
def count_sort(arr):
    
    sorted_arr = [ 0 for i in range(len(arr)) ] # Output array that will be sorted

    count_arr = [ 0 for i in range(10) ] # Count array of the input array

    for i in arr:
        count_arr[i] += 1
    
    for i in range(10):
        count_arr[i] += count_arr[i-1] #calculate the cumulative sum
    
    for i in range(len(arr)):
        m = count_arr[arr[i]] - 1
        sorted_arr[m] = arr[i]
        count_arr[arr[i]] -= 1
    
    return sorted_arr

arr = [3, 7, 0, 1, 2, 2, 3, 8, 4, 0]

print(count_sort(arr))