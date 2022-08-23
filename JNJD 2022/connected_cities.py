N, M = list(map(int, input().split()))
graph = [ [] for i in range(N) ]
edges = []
for i in range(M):
    u, v = list(map(int, input().split()))
    edges.append((u,v))

blocked = list(map(int, input().split()))
# for b in blocked:
#     if blocked[b] == 1:

for edge in edges:
    u, v = edge[0]-1, edge[1]-1
    if blocked[u] != 1:
        graph[u].append(v)
        graph[v].append(u)

visited = [False for i in range(N)]

# counts = []
# count = 0
def DFS(v):
    global count
    visited[v] = True
    count += 1
    for next in graph[v]:
        if not visited[next]:
            DFS(next)
    # print(count)
# DFS(6)
# print(count)

max_cities = 0
for i in range(N):
    count = 0
    visited = [False for i in range(N)]
    DFS(i)
    if count > max_cities:
        max_cities = count

print(max_cities)
print(graph)
