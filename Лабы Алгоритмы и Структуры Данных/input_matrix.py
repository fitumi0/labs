import os

path = 'txts/'
list_of_files = []
matrix = []

def select_file(path, new=''):
    for i in os.listdir(path):
        if i.__contains__('.txt'):
            list_of_files.append(i)
    for i in list_of_files:
        new += (str(list_of_files.index(i) + 1) + ') ' + i + '\n')
    while True:
        try:
            c = input(new + '\nВыберите файл содержащий матрицу смежности (!) : ')
            if int(c) not in range(1, len(list_of_files) + 1):
                raise ValueError
            else:
                break
        except ValueError:
            print("Выберите нужный из списка файл!\n")
    return list_of_files[int(c) - 1]


def start(file, id = -1):
    with open(path+file, 'r') as f:
        for line in f:
            id += 1
            matrix.append([])
            line = line.replace(',', '')
            L = line.strip().split(' ')
            for i in L:
                try:
                    i = int(i)
                except:
                    print('Неверный формат матрицы. Примеры:\n'
                          '0, 1,         0 0\n'
                          '1, 0,         1 0')
                    quit(0)
                matrix[id].append(i)
    return matrix


if __name__ == "__main__":
    start(select_file(path))