import os
import random
import input_matrix as ip

list_of_files = []
visited_bfs = []
id = -1
n_edges = 0


def select_search():
    while True:
        try:
            c = input('\nАлгоритмы : \n'
                      '1 - Определить число компомнентов связности\n'
                      '2 - Определить диаметр графа\n'
                      '//############ - Проверка на наличие циклов. - 50/50\n\n'
                      'Выберите алгоритм: ')
            c = c.lstrip().rstrip()
            if int(c) not in range(1, 4):
                raise ValueError
            else:
                break
        except ValueError:
            pass
    return int(c)


def dfs(v: int):
    visited_dfs[v] = True
    for i in range(len(matrix[v])):
        if (matrix[v][i] != 0 or matrix[i][v]) and visited_dfs[i] is False:
            dfs(i)


def dfs2(v: int):
    print(visited_dfs)
    visited_dfs[v] = True
    for i in range(len(matrix[v])):
        if (matrix[v][i] != 0 or matrix[i][v]) and visited_dfs[i] is False:
            dfs2(i)
        elif (matrix[v][i] != 0 or matrix[i][v]) and visited_dfs[i] is True:
            print("Граф имеет цикл!")
            quit(0)

def find_components(v, counter=1):
    dfs(v)
    for index in range(len(visited_dfs)):
        if not visited_dfs[index]:
            counter += 1
            dfs(index)
    return counter


def bfs(v):
    q = []
    visited_bfs = [False] * len(matrix[0])
    visited_bfs[v] = True
    d = [0] * len(matrix[0])
    q.append(v)
    while q:
        v = q.pop(0)
        i = 0
        while i < len(matrix[0]):
            if matrix[v][i] == 1 and visited_bfs[i] is False:
                q.append(i)
                visited_bfs[i] = True
                d[i] = d[v] + 1
            i += 1
    return d


def diameter(v):
    d = 0
    if find_components(v) == 1:
        if visited_bfs.count(True) == len(matrix[0])-1:
            d = bfs(v)
            d = d.index(max(d))
            return f"Диаметр графа: {max(bfs(d))}"
        else:
            for i in range(len(matrix[0])):
                if max(bfs(i)) > d:
                    d = max(bfs(i))
        return f"Диаметр графа: {d}"
    else:
        return 'Граф не является связным!'

path = 'txts/'
matrix = ip.start(ip.select_file(path))

for i in matrix:
    for j in i:
        if j == 1:
            n_edges += 1

print(matrix)
visited_dfs = [False] * len(matrix)
# print(f'Выбран файл: \"../{file}\"')
algo = select_search()
if algo == 1:
    print('Число компонентов связности:', find_components(random.randint(0, len(matrix[0]) - 1)))
elif algo == 2:
    start = random.randint(0, len(matrix[0]) - 1)
    print(diameter(start))
elif algo == 3:
    i = 0
    while i < len(matrix[0]):
        if visited_dfs[i] is False:
            dfs2(i)
        i += 1
    print("Граф не имеет циклов!")

