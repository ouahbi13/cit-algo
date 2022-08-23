L = input().split()
N, a, b, c = list(map(int, L))

if N-1 < min([a, b, c]): print("impossible")
else: print("possible")