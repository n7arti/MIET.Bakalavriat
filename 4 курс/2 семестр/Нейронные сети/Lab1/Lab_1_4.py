# Нейронные сети
# Лабораторная работа 1
# Программирование функций активации нейрона (перцептрона)


import numpy as np
import matplotlib.pyplot as plt


# Простая кусочно-линейная функция
def simple_piecewise_linear(v, v0):
    x1 = list()
    x2 = list()
    y1 = list()
    y2 = list()
    for i in v:
        if i <= v0:
            y1.append(0)
            x1.append(i)
        else:
            y2.append(1)
            x2.append(i)
    plt.plot(x1, y1, 'b')
    plt.plot(x2, y2, 'b')
    plt.grid()
    plt.show()
    print('Простая кусочно-линейная функция')
    print(np.column_stack((v, np.concatenate([y1, y2]))))


# Кусочно-линейная функция
def piecewise_linear(v, v0, v1):
    y = list()
    x = list()
    for i in v:
        if i <= v0:
            y.append(0)
            x.append(i)
        elif i >= v1:
            y.append(1)
            x.append(i)
        else:
            y.append((i - v0) / (v1 - v0))
            x.append(i)

    plt.plot(x, y, 'b')
    plt.grid()
    plt.show()
    print('Кусочно-линейная функция')
    print(np.column_stack((v, y)))


# Производная сигмоидной функции
def derivative(v, y):
    ch = list()
    ch.append(y[0])
    for i in range(0, len(v) - 1):
        ch.append((y[i + 1] - y[i]) / (v[i + 1] - v[i]))
    t = (2 * np.exp(2 * v)) / (np.exp(4 * v) + 2 * np.exp(2 * v) + 1)
    plt.plot(v, ch, 'b', label='Численно')
    plt.plot(v, t, 'r', label='Теоретически')
    plt.legend()
    plt.grid()
    plt.show()


# Логистическая функция
def log_fun(v, a):
    y = 1 / (1 + np.exp(-a * v))
    plt.plot(v, y, 'b')
    plt.grid()
    plt.show()
    print('Логистическая функция')
    print(np.column_stack((v, y)))
    derivative(v, y)


# Гиперболический тангенс
def hyperbolic_tg(v, a):
    y = np.tanh(v / a)
    plt.plot(v, y, 'b')
    plt.grid()
    plt.show()
    print('Гиперболический тангенс')
    print(np.column_stack((v, y)))


def neuron_activation(v, v0, v1, a):
    simple_piecewise_linear(v, v0)
    piecewise_linear(v, v0, v1)
    log_fun(v, a)
    hyperbolic_tg(v, a)


arr = np.arange(-10, 10, 0.5)
neuron_activation(arr, 0, 3, 2)
