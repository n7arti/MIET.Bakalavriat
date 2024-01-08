# Нейронные сети
# Лабораторная работа 2
# Нейрон Мак-Каллока — Питтса. Перцептрон. Логические нейронно-сетевые операции
# Реализация функции "Исключающее ИЛИ" (англ. " XOR") с использованием нейрона Мак-Каллока-Питтса

import numpy as np

# Задание весов и значения порога
print('Введите веса')
w_11 = float(input('Вес w_11 = '))
w_12 = float(input('Вес w_12 = '))
w_21 = float(input('Вес w_21 = '))
w_22 = float(input('Вес w_22 = '))
w11 = float(input('Вес w11 = '))
w12 = float(input('Вес w12 = '))
print('Введите величину порога')
theta = float(input('Порог = '))
y = np.array([0, 0, 0, 0])
y1=np.array([0, 0, 0, 0])
y2=np.array([0, 0, 0, 0])
x1 = np.array([1, 0, 1, 0])
x2 = np.array([1, 1, 0, 0])
z = np.array([0, 1, 1, 0])
con = 1
while con != 0:
    zin1 = x1 * w_11 + x2 * w_21
    zin2 = x1 * w_12 + x2 * w_22
    for i in range(0, 4):
        if zin1[i] >= theta:
            y1[i] = 1
        else:
            y1[i] = 0
        if zin2[i] >= theta:
            y2[i] = 1
        else:
            y2[i] = 0

    zin = y1 * w11 + y2 * w12
    for i in range(0, 4):
        if zin[i] >= theta:
            y[i] = 1
        else:
            y[i] = 0
    print('Значение на выходе нейрона')
    print(y)
    if all(y == z):
        con = 0
    else:
        print('Нейрон не обучен. Ввведите другие значения весовых коэффициентов и порога')
        w_11 = float(input('Вес w_11 = '))
        w_12 = float(input('Вес w_12 = '))
        w_21 = float(input('Вес w_21 = '))
        w_22 = float(input('Вес w_22 = '))
        w11 = float(input('Вес w11 = '))
        w12 = float(input('Вес w12 = '))
        theta = float(input('Порог = '))

print('Нейрон МакКаллока-Питса для функции "Исключающее ИЛИ" (англ. "XOR")')
print('Веса нейрона')
print(w_11)
print(w_12)
print(w_21)
print(w_22)
print(w11)
print(w12)
print('Пороговое значение')
print(theta)
