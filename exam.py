# 1) Способы представления графов

# Матрица

matrix = [[0, 3, 0, 7, 0, 1],
          [0, 0, 3, 0, 11, 0],
          [0, 0, 0, 0, 0, 1],
          [0, 0, 0, 0, 3, 0],
          [0, 0, 3, 0, 0, 0],
          [0, 0, 0, 0, 0, 0]]

print(f"Example matrix: {matrix}\n"
      f"=====================================")

# Список смежности
#
# adj = {'A': {'B', 'C'},
#        'B': {'A', 'D', 'E'},
#        'C': {'A', 'F'},
#        'D': {'B'},
#        'E': {'B', 'F'},
#        'F': {'C', 'E'}}
#
# print(f"Example adjacency list: {adj}\n"
#       f"=====================================")

# 2) BFS, простой обход
start = 0
def bfs(v):
    q = []
    used = [False] * len(matrix[0])
    used[v] = True
    q.append(v)
    while q:
        v = q.pop(0)
        i = 0
        while i < len(matrix[0]):
            if matrix[v][i] == 1 and used[i] is False:
                q.append(i)
                used[i] = True
            i += 1
    return used


print(f"BFS result (start from {start}): {bfs(start)}\n"
      f"=====================================")


# 3) DFS, простой обход

def dfs(v: int, used=[False] * len(matrix)):
    used[v] = True
    for i in range(len(matrix[v])):
        if (matrix[v][i] != 0) and used[i] is False:
            dfs(i)
    return used


print(f"DFS result (start from {start}): {dfs(start)}\n"
      f"=====================================")


# 4) Алгоритм Дейкстры. Кратчайший путь от одной вершины до всех остальных

def dijkstra(src):
    used = []
    d = {src: 0}
    node = list(range(len(matrix[0])))
    if src in node:
        node.remove(src)
        used.append(src)
    else:
        return None
    for i in node:
        d[i] = matrix[src][i]
    prefer = src
    while node:
        dist0 = float('inf')
        for i in used:
            for j in node:
                if matrix[i][j] > 0:
                    if dist0 > d[i] + matrix[i][j]:
                        dist0 = d[j] = d[i] + matrix[i][j]
                        prefer = j
        used.append(prefer)
        node.remove(prefer)
    return d

print(f"dijkstra result (start from {start}): {dijkstra(start)}\n"
      f"=====================================")


def floyd_warshall(n=len(matrix), d = matrix):
    for i in range(n):
        for u in range(n):
            for v in range(n):
                d[u][v] = min(d[u][v], d[u][i] + d[i][v])
    return d


print(f"Floyd Warshall result: {floyd_warshall()}\n"
      f"=====================================")


def bellman_ford(v):
    m = 0
    for i in matrix:
        for j in i:
            if j != 0:
                m += 1

    # перевод в список рёбер из матрицы смежности
    adj = []
    for i in matrix:
        for j in i:
            if j != 0:
                adj.append({matrix.index(i), j})
    print(adj)


    # d = [float('inf')] * len(matrix[0])
    # d[v] = 0
    # while True:
    #     a = False
    #     for i in range(len(matrix[0])-1):
    #         for j in range(m):

bellman_ford(0)



def kruskal():
    pass


def prim(n = len(matrix[0])):
    selected = [0] * n
    no_edge = 0
    selected[0] = True
    print("Edge : Weight")
    while no_edge < n - 1:
        minimum = float('inf')
        x = 0
        y = 0
        for i in range(n):
            if selected[i]:
                for j in range(n):
                    if (not selected[j]) and matrix[i][j]:
                        if minimum > matrix[i][j]:
                            minimum = matrix[i][j]
                            x = i
                            y = j
        print(str(x) + "-" + str(y) + ":" + str(matrix[x][y]))
        selected[y] = True
        no_edge += 1

print(f"Algorithm Prima result: {prim()}\n"
      f"=====================================")


def lca():
    pass


used_h = [False] * len(matrix[0])
p = []
def hamilton(v):
    p.append(v)
    if len(p) == len(matrix[0]):
        if matrix[p[0]][p[-1]] != 0:
            return True
        else:
            p.pop()
            return False
    used_h[v] = True
    for next in range(len(matrix[0])):
        if matrix[v][next] != 0 and not used_h[next]:
            if hamilton(next):
                return True
    used_h[v] = False
    p.pop()
    return False


print(f"Find Hamilton cycle result: {hamilton(0)}\n"
      f"=====================================")