import numpy as np
import input_matrix as inp

path = 'txts/'
matrix = inp.start(inp.select_file(path))

verb_list_out = []
for x in range(len(matrix[0])):
    verb_list_out.append(0)

# v - start vertex, d - destination
def bfs(v, d, parent: list):
    used = [False] * len(matrix[0])
    q = []
    q.append(v)
    used[v] = True
    while q:
        v = q.pop(0)
        i = 0
        while i < len(matrix[0]):
            if matrix[v][i] != 0 and used[i] is False:
                q.append(i)
                used[i] = True
                # запоминаем предков
                parent[i] = v
            i += 1
    return True if used[d] else False


# поиск количества выходящих рёбер из каждой вершины
def search_out(matrix):
    for i in matrix:
        out = 0
        for j in i:
            if j != 0:
                out += 1
        verb_list_out[matrix.index(i)] = out
    return verb_list_out.index(0)


# поиск количества входящих рёбер из каждой вершины
# путём транспонирования матрицы (ориентированность развернётся)
def search_in(matrix):
    # транспонируем
    a = np.matrix(matrix).T.tolist()
    # запускаем поиск выходящих вершин
    search_out(a)
    # ответ удивляет
    return verb_list_out.index(0)


def EdmondsKarp(start: int, end: int):
    parent = [-1] * len(matrix[0])
    # обнуляем макс. поток
    max_flow = 0
    # увеличиваем максимальный поток пока bfs возвращает True
    while bfs(start, end, parent):
        # устанавливаем пути равными бесконечности
        path_flow = float("inf")
        s = end
        # ищем макс поток на найденном пути
        while s != start:
            path_flow = min(path_flow, matrix[parent[s]][s])
            s = parent[s]
        # добавляем к общему потоку
        max_flow += path_flow
        v = end
        while v != start:
            u = parent[v]
            # Для каждого ребра увеличиваем поток
            matrix[v][u] += path_flow
            # для каждого обратного уменьшаем
            matrix[u][v] -= path_flow
            v = parent[v]
    # print(matrix)
    return max_flow


if __name__ == "__main__":
    start = search_in(matrix)
    end = search_out(matrix)
    print(f"Исток: {start}\nСток: {end}")
    print(f"Максимальный поток равен: {EdmondsKarp(start, end)}")
