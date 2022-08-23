N = int(input())
# M = [
#     [2, 2, 2, 2],
#     [2, 3, 2, 3],
#     [2, 2, 2, 3],
#     [2, 2, 2, 2]
# ]

M = []

for i in range(N):
    M.append(list(map(int, input().split())))

t, r, c = 0, 0, 0

for row in M:
    if len(row) != len(set(row)): r += 1

M_T = [ [0]*N for i in range(N)]
for i in range(len(M)):
    for j in range(len(M)):
        M_T[i][j] = M[j][i]

for column in M_T:
    if len(column) !=len(set(column)): c += 1

for i in range(N):
    t += M[i][i]

print(t, r, c)




