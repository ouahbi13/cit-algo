N, M, Q = list(map(int, input().split()))
p_a = sorted(list(map(int, input().split())))
p_b = sorted(list(map(int, input().split())))

for i in  range(Q):
    c = int(input())
    result = 0
    i, j = 0, M-1
    while i < N and j >= 0:
        if p_a[i] + p_b[j] == c: 
            result += 1
            i += 1
            j -= 1
        elif p_a[i] + p_b[j] < c:
            i += 1
        else:
            j -= 1
    
    # if i == N-1:
    #     for jj in range(j, 0, -1):
    #         if p_a[i] + p_b[jj] == c: 
    #             result += 1
    #         # print("j", j)
    
    # elif j == 0:
    #     for ii in range(i, N):
    #         if p_a[ii] + p_b[j] == c: 
    #             result += 1


    print(result)



    # for n in range(N):
        # if p_a[n] + p_b[0] > c: break
        # for m in range(M):
        #     if p_a[n] + p_b[m] == c: result += 1
    # print(result)