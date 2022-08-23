L = input().split()
n, m = list(map(int, L))

MOD = 1000000007
def fibonnaci(n, m):
    
    f = [0, 1, 1, 2]
    for i in range(4, n+1):
        # s = 0
        # for j in range(1, m+1):
        #     s += f[i-j]
        # s = 
        f.append(sum(f[-m:]))
    return f[n] % MOD

print(fibonnaci(n, m))