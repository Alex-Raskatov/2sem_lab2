import matplotlib.pyplot as plt
import numpy as np

def foo(file_name, graph_name):

    file = open(file_name, 'r', encoding='utf-8')
    t = list(map(lambda x: x.rstrip().split(), file.readlines()))
    file.close()

    x = []
    y = []

    for i in range(len(t)):
        x.append(float(t[i][0]))
        y.append(float(t[i][1]))

    x = np.array(x)
    y = np.array(y)

    plt.figure(figsize=(20,12))

    plt.plot(x, y,'o', color = 'black')
    plt.title('')
    plt.ylabel('')
    plt.xlabel('')
    plt.minorticks_on()
    plt.grid(visible=True, which='major', axis='both', alpha=1)
    plt.grid(visible=True, which='minor', axis='both', alpha=0.2)
    plt.savefig(graph_name)



file_name = input()

foo(file_name, file_name[:-8] + "graph.png")