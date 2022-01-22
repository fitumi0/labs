import input_matrix as inp

path = 'txts/'
matrix = inp.start(inp.select_file(path))


# возвращает True, если мы нашли увеличивающую цепь из вершины
def kuhn(v:int, f:list, mt):
    # пропускаем пройденную вершину
    if f[v]:
        return False
    f[v] = True
    for i in range(len(matrix[v])):
        if matrix[v][i] == 1:
            if mt[i] == -1 or kuhn(mt[i], f, mt):
                mt[i] = v
                return True
    return False


def run():
    # список паросочетаний
    a: list = []
    # список вершин, по которому строится {a}
    mt = [-1] * len(matrix[0])

    # серия обходов
    for v in range(len(matrix[0])):
        f = [False] * len(matrix[0])
        kuhn(v, f, mt)
    # заполнение списка паросочетаний
    for i in range(len(mt)):
        if mt[i] != -1 and not a.__contains__(([mt[i], i])):
                a.append([i, mt[i]])
    if len(a) != 0:
        print(f"Рёбра, включённые в паросочетание: {a}\n"
              f"Количество рёбер в данном паросочетании: {len(a)}.")
    else:
        print("Паросочетаний нет.")

run()