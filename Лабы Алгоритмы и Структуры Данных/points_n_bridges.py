import input_matrix as ip

path = 'txts/'
matrix = ip.start(ip.select_file(path))


def select_():
    while True:
        try:
            c = input('\nАлгоритмы : \n'
                      '1 - Определить наличие мостов\n'
                      '2 - Определить наличие точек сочленения\n\n'
                      'Выберите алгоритм: ')
            c = c.lstrip().rstrip()
            if int(c) not in range(1, 3):
                raise ValueError
            else:
                break
        except ValueError:
            pass
    return int(c)


# v - корневая вершина, d - список времени входа, h - список времени выхода
# time - итератор "глубины", p - индекс вершины-предка, f - список флагов, c - счётчик "дочерних" элементов v
# point_list\bridge_list - список точек сочленения\мостов
def points(v: int, d: list, h: list, time: int = 0, p: int = -1, f: list = [False] * len(matrix[0]), c: int = 0,
           point_list: list = []):
    time += 1 # увеличиваем глубину захода
    d[v] = h[v] = time # для вершины устанавливаем "время"
    f[v] = True # отмечаем вершину пройденной
    for u in range(len(matrix[v])-1):
        if matrix[v][u] == 1:
            if u == p:
                continue
            if f[u]:
                h[v] = min(h[v], d[u])
            else:
                # если мы не были в вершине f[u] то запускаем рекурсивно ещё один поиск
                points(v=u, d=d, h=h, f=f, time=time, p=v, c=c, point_list=point_list)
                h[v] = min(h[v], h[u])
                if h[u] > d[v] and p != -1 and not point_list.__contains__([v]):
                    # добавляем вершину в список
                    point_list.append([v])
                c += 1
    if p == -1 and c > 1 and not point_list.__contains__([v]):
        point_list.append([v])
    return f, point_list


def bridges(v: int, d: list, h: list, time: int = 0, p: int = -1, f: list = [False] * len(matrix[0]),
            bridge_list: list = []):
    f[v] = True  # отмечаем вершину пройденной
    time += 1  # увеличиваем глубину захода
    d[v] = h[v] = time  # для вершины устанавливаем "время"
    for u in range(len(matrix[v])):
        if matrix[v][u] == 1:
            if u == p:
                continue
            if f[u]: # проверяем, обратное ли ребро
                h[v] = min(h[v], d[u])
            else:
                bridges(u, d=d, h=h, time=time, p=v)
                h[v] = min(h[v], h[u])
                if h[u] > d[v]:
                    bridge_list.append([v, u])
    return f, bridge_list


def check_bridges():
    d = h = [0] * len(matrix[0])
    f, bl = bridges(0, d=d, h=h)
    for u in range(len(matrix[0])):
        if not f[u]:
            f, bl = bridges(u, d=d, h=h, p=-1)
    if len(bl) == 0:
        print("Мостов не найдено")
    else:
        print("Список мостов:", bl[::-1])


def check_points():
    f: list = [False] * len(matrix[0])
    d = h = [0] * len(matrix[0])
    for u in range(len(matrix[0])):
        if not f[u]:
            f, pl = points(u, d=d, h=h, f=f, p=-1)
    if len(pl) == 0:
        print("Точек сочленения не найдено")
    else:
        print("Список точек сочленения:", pl[::-1])


if __name__ == "__main__":
    check_bridges()
    check_points()
