import generate_graphs

while True:
    try:
        inp = int(input('1) полный неориентированный \n'
                        '2) связный взвешенный (рёбра) \n'
                        '3) ориентированный без циклов \n'
                        '4) взвешенный ориентированный без циклов \n'
                        '5) ориентированный связный \n'
                        'Выберите нужную генерацию (1-5): '))
        if inp not in range(1, 6):
            raise ValueError
        else:
            while True:
                try:
                    nodes = int(input('Введите количество узлов: '))
                    if nodes < 1 or nodes > 50:
                        raise ValueError
                    else:
                        break
                except ValueError:
                    print('Количество узлов должно быть 1-50')
            break
    except ValueError:
        print('Введите корректное число')

color = 'c'

if inp == 1:
    generate_graphs.nx.draw(generate_graphs.nx.from_numpy_matrix(generate_graphs.complete_graph(nodes)), node_color=color,
                            node_size=750,
                            with_labels=True)
elif inp == 2:
    generate_graphs.nx.draw(generate_graphs.nx.from_numpy_matrix(generate_graphs.connected_graph(nodes, True)), node_color=color,
                            node_size=750,
                            with_labels=True)
elif inp == 3:
    generate_graphs.nx.draw_circular(generate_graphs.nx.from_numpy_matrix(generate_graphs.without_of_cycle(nodes, False)),
                                     node_color=color,
                                     node_size=750,
                                     with_labels=True)
elif inp == 4:
    generate_graphs.nx.draw(generate_graphs.nx.from_numpy_matrix(generate_graphs.without_of_cycle(nodes, True)), node_color=color,
                            node_size=750,
                            with_labels=True)
elif inp == 5:
    generate_graphs.nx.draw(generate_graphs.nx.from_numpy_matrix(generate_graphs.connected_graph(nodes, False)), node_color=color,
                            node_size=750,
                            with_labels=True)
else:
    print('Что-то пошло не так... Закрываемся.')

#new_graphs.plt.show()
# start = time.time()
# print("--- %s seconds ---" % (time.time() - start))
