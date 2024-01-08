# Нейронные сети
# Лабораторная работа 3
import numpy as np
import matplotlib.pyplot as plt
from neurolab.net import newff
from neurolab.tool import minmax
from neurolab.trans import LogSig, PureLin
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression


# Формирование входных массивов (входной массив P) и (эталоны T)
def mas1():
    P = np.zeros((100, 21))
    T = np.zeros((3, 100))
    x = np.arange(0, 1.05, 0.05)
    for i in range(0, 100):
        c = 0.9 * np.random.uniform(0, 1) + 0.1
        a = 0.9 * np.random.uniform(0, 1) + 0.1
        s = 0.9 * np.random.uniform(0, 1) + 0.1
        T[0, i] = c
        T[1, i] = a
        T[2, i] = s
        P[i, :] = c * np.exp(-((x - a) ** 2 / s))
    return (P, T.T)


# регрессионный анализ результатов обработки
def postreg(Ti, yi):
    X_train, X_test, y_train, y_test = train_test_split(yi.reshape(-1, 1), Ti.reshape(-1, 1), test_size=1 / 3,
                                                        random_state=0)
    regressor = LinearRegression()
    regressor.fit(X_train, y_train)
    y_pred = regressor.predict(X_test)

    plt.scatter(X_train, y_train, color='red')
    plt.plot(X_train, regressor.predict(X_train), color='blue')
    plt.show()


def proc(P, T):
    net = newff(minmax(P), [21, 15, 3], [LogSig(), LogSig(), PureLin()])
    E = net.train(
        input=P,
        target=T,
        epochs=1000,
        goal=0.01
    )
    plt.plot(E)
    plt.grid()
    plt.show()

    y = net.sim(P)
    for i in range(3):
        postreg(T[:, i], y[:, i])


def proc2(P, T):
    net = newff(minmax(P), [21, 15, 3], [LogSig(), LogSig(), PureLin()])
    E = net.train(
        input=P,
        target=T,
        epochs=1000,
        goal=0.01
    )
    plt.plot(E)
    plt.grid()
    plt.show()

    y = net.sim(np.random.uniform(0, 1, (100, 21)))
    for i in range(3):
        postreg(T[:, i], y[:, i])


def mas():
    P = np.zeros((100, 21))
    T = np.zeros((3, 100))
    x = np.arange(0, 1.05, 0.05)
    for i in range(0, 100):
        a = np.random.uniform(0, 1)
        b = np.random.uniform(0, 1)
        c = np.random.uniform(0, 1)
        T[0, i] = a
        T[1, i] = b
        T[2, i] = c
        P[i, :] = a * (x ** 2) + b * x + c
    return (P, T.T)


P, T = mas1()
print(P.shape)
print(T.shape)
proc(P, T)

P1 = P + np.random.uniform(0, 0.01, P.shape)
proc(P1, T)

P2 = P + np.random.uniform(0, 0.05, P.shape)
proc(P2, T)

P3 = P + np.random.uniform(0, 0.1, P.shape)
proc(P3, T)

P4 = P + np.random.uniform(0, 0.2, P.shape)
proc(P4, T)

P, T = mas()
print(P.shape)
print(T.shape)
proc2(P, T)
