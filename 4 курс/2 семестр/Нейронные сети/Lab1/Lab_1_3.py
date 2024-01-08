# Нейронные сети
# Лабораторная работа 1
# Оценка трудоемкости обработки данных с помощью ДПФ и БПФ

import numpy as np
import matplotlib.pyplot as plt
from timeit import default_timer as timer

print('*** Оценка трудоемкости обработки данных с помощью ДПФ и БПФ ***')
A = 2
f0 = 2000

# а) дискретизация и визуализация функций синуса и косинуса с частотой 2 кГц в двух вариантах: для заданного интервала наблюдения и для заданного количества точек
w = 2 * np.pi * f0  # Переход к круговой частоте (рад/сек)
dtn = np.pi / w  # Интервал дискретизации Найквиста (теорема Котельникова)

Tnab = float(input("Введите интервал наблюдения: "))
Nn = int(input("Введите количество точек: "))
phi = float(input('Введите фазу сигнала, рад: '))

tn = np.multiply(dtn,
                 np.arange(0, Nn - 1))  # Вектор времени (сек), дискретизированный в соответствии с критерием Найквиста

Nv = int(Tnab / dtn)
print('Количество точек в интервале наблюдения для интервала дискретизации = ', Nv)
tv = np.multiply(dtn,
                 np.arange(0, Nv - 1))  # Вектор времени (сек), дискретизированный в соответствии с критерием Найквиста
y1n = A * np.cos(2 * np.pi * f0 * tn + phi)
y2n = A * np.sin(2 * np.pi * f0 * tn + phi)
# Вектора сигналов, дискретизированных в соответствии с критерием Найквиста
y1v = A * np.cos(2 * np.pi * f0 * tv + phi)
y2v = A * np.sin(2 * np.pi * f0 * tv + phi)
# Вектора сигналов, дискретизированныхc интервалом дискретизации, пригодным для визуализации

plt.figure(1)
plt.subplot(2, 2, 1)
plt.plot(tn, y1n, 'r-*')
plt.axis([0, tn[-1], - 1.1 * A, 1.1 * A])
plt.title('Косинус по количеству точек')
plt.ylabel('Signal')

plt.subplot(2, 2, 2)
plt.plot(tv, y1v, 'b')
plt.axis([0, Tnab, - 1.1 * A, 1.1 * A])
plt.title('Косинус по интервалу наблюдения')
plt.ylabel('Signal')

plt.subplot(2, 2, 3)
plt.plot(tn, y2n, 'r-*')
plt.axis([0, tn[-1], - 1.1 * A, 1.1 * A])
plt.title('Синус по количеству точек')
plt.xlabel('Time, sec')
plt.ylabel('Signal')

plt.subplot(2, 2, 4)
plt.plot(tv, y2v, 'b')
plt.axis([0, Tnab, - 1.1 * A, 1.1 * A])
plt.title('Синус по интервалу наблюдения')
plt.xlabel('Time, sec')
plt.ylabel('Signal')
plt.show()

# б) вычислить фурье-образы исходных сигналов с помощью прямого вычисления ДПФ и с помощью БПФ, реализованного в Python(функция numpy.fft);
# в) визуально сравнить реальные и мнимые части фурье-образов и квадраты их модулей.
fdn = 2 * f0  # Частота дискретизации
# в соответствии с критерием Найквиста
mvis = 4
fdv = mvis * fdn  # Частота дискретизации для визуализации
dt = 1 / fdv  # Интервал дискретизации по времени
T = 1 / f0  # Период сигнала
NT = 6
t = np.arange(0, NT * T, dt)  # Вектор времени, с
y = A * np.sin(2 * np.pi * f0 * t)
# Вектор сигнала
N = len(y)
k = np.arange(N)
ff = k * fdv / N  # Вектор частоты, Гц

# DFT
Ex = np.exp(-1j * 2 * (np.pi / N) * np.transpose(k) * k)
Y_dft = np.array(y * Ex)
Y_dft2 = Y_dft * np.conj(Y_dft)  # Квадрат модуля Фурье - образа

# FFT
Y_fft = np.fft.fft(y)
Y_fft2 = Y_fft * np.conj(Y_fft)  # Квадрат модуля Фурье - образа

plt.figure(2)
plt.subplot(3, 1, 1)
plt.plot(ff, np.real(Y_dft), 'b')
plt.title('DFT real part')

plt.subplot(3, 1, 2)
plt.plot(ff, np.imag(Y_dft), 'b')
plt.title('DFT imaginary part')

plt.subplot(3, 1, 3)
plt.plot(ff, Y_dft2, 'b')
plt.title('DFT^2')

plt.figure(3)
plt.subplot(3, 1, 1)
plt.plot(ff, np.real(Y_fft), 'b')
plt.title('FFT real part')

plt.subplot(3, 1, 2)
plt.plot(ff, np.imag(Y_fft), 'b')
plt.title('FFT imaginary part')

plt.subplot(3, 1, 3)
plt.plot(ff, Y_fft2, 'b')
plt.title('FFT^2')
plt.show()

# Построить график зависимости времени обработки исходных данных с помощью ДПФ и БПФ, варьируя размерность исходного массива 2s от 128 (s = 7) до 4096 (s = 12).
dft_time = []
fft_time = []
mass = []

for i in range(7, 11):
    NT = 2 ** i
    mass.append(NT)

    t = np.arange(0, NT * T, dt)  # Вектор времени, с
    y = A * np.sin(2 * np.pi * f0 * t)
    # Вектор сигнала
    N = len(y)
    k = np.arange(N)
    ff = k * fdv / N

    # dft
    start = timer()
    Ex = np.exp(-1j * 2 * (np.pi / N) * np.transpose(k) * k)
    np.multiply(y, Ex)
    end = timer()
    dft_time.append(end - start)

    # fft
    start = timer()
    np.fft.fft(y)
    end = timer()
    fft_time.append(end - start)

plt.figure(4)
plt.plot(mass, dft_time, 'b', label='DFT')
plt.plot(mass, fft_time, 'r', label='FFT')
plt.xlabel('Количество периодов наблюдения')
plt.ylabel('Time')
plt.legend()
plt.show()

print('**********   Конец работы   **********')
