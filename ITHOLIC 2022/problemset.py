L = list(map(lambda x: int(x), input().split(' ')))
k, a, b, m = L[0], L[1], L[2], L[3]

D = list(map(lambda x: int(x), input().split(' ')))

valid_problemsets = 0

x = [ 0 for i in range(len(D)) ]

combinaisons = []

def sum_of_subset(s, k, r, S):
    x[k] = 1

    if s + D[k] == S: combinaisons.append(x[0:k+1])
    elif s + D[k] + D[k+1] <= S:
        sum_of_subset(s+D[k], k+1, r-D[k], S)
    if s+r-D[k] >= S and s+D[k+1] <= S:
        x[k] = 0
        sum_of_subset(s, k+1, r-D[k], S)

for S in range(a, b+1):
    sum_of_subset(0, 0, sum(D), S)

for comb in combinaisons:
    L = []
    for k in range(len(D)):
        if comb[k]: L.append(D[k])
    if L and max(L) - min(L) >= m: valid_problemsets += 1

print(valid_problemsets)

