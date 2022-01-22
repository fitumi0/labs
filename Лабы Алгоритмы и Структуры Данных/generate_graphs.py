import numpy as np
import random as rn


def edges(adj):
    for i, neighbors in enumerate(adj):
        for j, v in enumerate(neighbors):
            if v:
                yield i, j


def complete_graph(n):
    matrix = np.zeros((n, n))
    edge_list, x = [], []  # x - list for generate matrix
    for i in range(n):
        x.append(i)
    for i in x:
        for j in x:
            if i != j and i < j:
                matrix[i, j] = 1
    for edge in edges(matrix):
        edge_list.append(edge)
    with open('txts/полный граф MATRIX.txt', 'w') as f1:
        for line in matrix.tolist():
            for i in line:
                f1.write('%-1d' % i + ' ')
            f1.write('\n')
    with open('txts/двудольный(2).txt', 'w') as f2:
        edge_list.reverse()
        while len(edge_list) > 0:
            f2.write(str(edge_list[-1]) + '\n')
            edge_list.pop(len(edge_list) - 1)
    return matrix


def connected_graph(n, w: bool):
    matrix = np.zeros((n, n))
    edge_list, x = [], []
    while True:
        try:
            component = int(input(f'Введите количество компонент связности не превышающее половину от количества узлов - {n // 2}: '))
            if component < 1 or component > n // 2:
                raise ValueError
            else:
                break
        except ValueError:
            print('Количество компонент связности должно быть больше нуля и целочисленным значением,'
                  f' а также не должно превышать половину от количества узлов - {n // 2}.\n')
    while True:
        try:
            num_of_edges = int(input('Введите количество рёбер: '))
            if num_of_edges not in range(1, (n*(n-1)//2)):
                raise ValueError
            else:
                if component > 1 and num_of_edges > n - component:
                    raise ValueError
                else:
                    break
        except ValueError:
            print(f'Количество рёбер должно быть от 1 до (n(n-1)//2) - 1 ({(n * (n - 1) // 2) - 1})\n'
                  f'Если количество компонент > 1 то не должно превышать {n - component}')
    while True:
        if w:
            try:
                max_weight = int(input('Введите максимальный вес ребра: '))
                if (max_weight < 1) or (max_weight > 100):
                    raise ValueError
                else:
                    number1 = 'связный взвешенный (рёбра) MATRIX.txt'
                    number2 = 'связный взвешенный (рёбра) LIST.txt'
                    break
            except ValueError:
                print('Допустимый вес ребра 1-100. \n')
        else:
            number1 = 'ориентированный связный MATRIX.txt'
            number2 = 'ориентированный связный LIST.txt'
            max_weight = 1
            break
    for i in range(n):
        x.append(i)
    for i in x:
        for j in x:
            if i < j:           # заполняем матрицу над главной диагональю
                if i != j and num_of_edges != 0 and component == 1:  # количество компонент связности и количество рёбер
                    matrix[i, j] = rn.randint(1, max_weight)
                    num_of_edges -= 1
                elif i != j and i == j % component and num_of_edges != 0 and component > 1:
                    matrix[i, j] = rn.randint(1, max_weight)
                    num_of_edges -= 1
    for edge in edges(matrix):
        edge_list.append(edge)
    with open('txts/' + number1, 'w') as f1:
        for line in matrix.tolist():
            for i in line:
                f1.write('%-1d' % i + ' ')
            f1.write('\n')
    with open('txts/' + number2, 'w') as f2:
        edge_list.reverse()
        while len(edge_list) > 0:
            f2.write(str(edge_list[-1]) + '\n')
            edge_list.pop(len(edge_list) - 1)
    return matrix


def without_of_cycle(n, w: bool):

    matrix = np.zeros((n, n))
    edge_list, x = [], []
    while True:
        try:
            num_of_edges = int(input(f'Введите количество рёбер не превышающее {(n * (n - 1) // 2) - 1}: '))
            if num_of_edges not in range(1, (n*(n-1)//2)):
                raise ValueError
            else:
                break
        except ValueError:
            print(f'Количество рёбер должно быть от 1 до (n(n-1)//2) - 1 ({(n * (n - 1) // 2) - 1})\n')
    while True:
        if w:
            try:
                max_weight = int(input('Введите максимальный вес ребра: '))
                if (max_weight < 1) or (max_weight > 100):
                    raise ValueError
                else:
                    number1 = 'взвешенный ориентированный без циклов MATRIX.txt'
                    number2 = 'взвешенный ориентированный без циклов LIST.txt'
                    break
            except ValueError:
                print('Допустимый вес ребра 1-100. \n')
        else:
            number1 = 'ориентированный без циклов MATRIX.txt'
            number2 = 'ориентированный без циклов LIST.txt'
            max_weight = 1
            break
    for i in range(n):
        x.append(i)
    for i in x:
        for j in x:
            if i < j:
                if i != j and num_of_edges != 0:
                    if w:
                        matrix[i, j] = rn.randint(1, max_weight)
                    else:
                        matrix[i, j] = 1
                    num_of_edges -= 1
    for edge in edges(matrix):
        edge_list.append(edge)

    with open('txts/' + number1, 'w') as f1:
        for line in matrix.tolist():
            for i in line:
                f1.write(str('%-0d' % i) + ' ')
            f1.write('\n')
    with open('txts/' + number2, 'w') as f2:
        edge_list.reverse()
        while len(edge_list) > 0:
            f2.write(str(edge_list[-1]) + '\n')
            edge_list.pop(len(edge_list) - 1)
    return matrix
