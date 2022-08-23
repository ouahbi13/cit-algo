import io, os

def closestRight(i):
    d_taller = 0
    for j in range(i+1, N):
        d_taller += 1
        if D[i] <= D[j]:
            return d_taller
    return -1

def closestLeft(i):
    d_taller = 0
    for j in range(i-1, -1, -1):
        d_taller += 1
        if D[i] <= D[j]:
            return d_taller
    return -1

# T = int(input())
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
T = input().decode()
print(T)

# print(input)
# for i in range(T):
#     input = io.BytesIO(os.read(0, \
#          os.fstat(0).st_size)).readline

#     N = int(input().decode())
#     input = io.BytesIO(os.read(0, \
#          os.fstat(0).st_size)).readline
#     D = list(map(int, input().decode().split()))
#     s = ""
#     for i in range(N):
#         if closestLeft(i) == -1 or closestRight(i) == -1:
#             s += str(max(closestLeft(i), closestRight(i))) + " "
#         else:
#             s += str(min(closestLeft(i), closestRight(i))) + " "
#     print(s.strip())





