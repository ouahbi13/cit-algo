n, m = list(map(int, input().split()))
array = []

for p in range(n):
    array.append(list(map(int, input().split())))

N = int(input())
count = 0
for i in range(n):
    for j in range(m):
        if i < n-1:
            if array[i][j] == 0 and array[i+1][j] == 0:
                count += 2
                array[i][j] = 1
                array[i+1][j] = 1
        elif j < m-1:
            if array[i][j] == 0 and array[i][j+1] == 0:
                count += 2
                array[i][j] = 1
                array[i][j+1] = 1

if count >= N: print("Yes")
else: print("No")