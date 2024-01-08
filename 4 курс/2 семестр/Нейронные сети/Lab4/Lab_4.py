import tensorflow as tf
from keras import layers
import numpy as np
from collections import deque
import random
import matplotlib.pyplot as plt
import os
from PIL import Image
import pandas as pd
from sklearn import neural_network as nn
from sklearn.metrics import confusion_matrix, accuracy_score


def english():
    def get_alphabet():
        letterA = [0, 0, 1, 0, 0,
                   0, 1, 0, 1, 0,
                   0, 1, 0, 1, 0,
                   1, 0, 0, 0, 1,
                   1, 1, 1, 1, 1,
                   1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1]

        letterB = [1, 1, 1, 1, 0,
                   1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1,
                   1, 1, 1, 1, 0,
                   1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1,
                   1, 1, 1, 1, 0]

        letterC = [0, 1, 1, 1, 0,
                   1, 0, 0, 0, 1,
                   1, 0, 0, 0, 0,
                   1, 0, 0, 0, 0,
                   1, 0, 0, 0, 0,
                   1, 0, 0, 0, 1,
                   0, 1, 1, 1, 0]

        letterD = [1, 1, 1, 1, 0,
                   1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1,
                   1, 1, 1, 1, 0]

        letterE = [1, 1, 1, 1, 1,
                   1, 0, 0, 0, 0,
                   1, 0, 0, 0, 0,
                   1, 1, 1, 1, 1,
                   1, 0, 0, 0, 0,
                   1, 0, 0, 0, 0,
                   1, 1, 1, 1, 1]

        letterF = [1, 1, 1, 1, 1,
                   1, 0, 0, 0, 0,
                   1, 0, 0, 0, 0,
                   1, 1, 1, 1, 0,
                   1, 0, 0, 0, 0,
                   1, 0, 0, 0, 0,
                   1, 0, 0, 0, 0, ]

        letterG = [0, 1, 1, 1, 0,
                   1, 0, 0, 0, 1,
                   1, 0, 0, 0, 0,
                   1, 0, 0, 0, 0,
                   1, 0, 0, 1, 1,
                   1, 0, 0, 0, 1,
                   0, 1, 1, 1, 0, ]

        letterH = [1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1,
                   1, 1, 1, 1, 1,
                   1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1, ]

        letterI = [0, 1, 1, 1, 0,
                   0, 0, 1, 0, 0,
                   0, 0, 1, 0, 0,
                   0, 0, 1, 0, 0,
                   0, 0, 1, 0, 0,
                   0, 0, 1, 0, 0,
                   0, 1, 1, 1, 0, ]

        letterJ = [1, 1, 1, 1, 1,
                   0, 0, 1, 0, 0,
                   0, 0, 1, 0, 0,
                   0, 0, 1, 0, 0,
                   0, 0, 1, 0, 0,
                   1, 0, 1, 0, 0,
                   0, 1, 0, 0, 0, ]

        letterK = [1, 0, 0, 0, 1,
                   1, 0, 0, 1, 0,
                   1, 0, 1, 0, 0,
                   1, 1, 0, 0, 0,
                   1, 0, 1, 0, 0,
                   1, 0, 0, 1, 0,
                   1, 0, 0, 0, 1, ]

        letterL = [1, 0, 0, 0, 0,
                   1, 0, 0, 0, 0,
                   1, 0, 0, 0, 0,
                   1, 0, 0, 0, 0,
                   1, 0, 0, 0, 0,
                   1, 0, 0, 0, 0,
                   1, 1, 1, 1, 1, ]

        letterM = [1, 0, 0, 0, 1,
                   1, 1, 0, 1, 1,
                   1, 0, 1, 0, 1,
                   1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1, ]

        letterN = [1, 0, 0, 0, 1,
                   1, 1, 0, 0, 1,
                   1, 1, 0, 0, 1,
                   1, 0, 1, 0, 1,
                   1, 0, 0, 1, 1,
                   1, 0, 0, 1, 1,
                   1, 0, 0, 0, 1, ]

        letterO = [0, 1, 1, 1, 0,
                   1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1,
                   0, 1, 1, 1, 0, ]

        letterP = [1, 1, 1, 1, 0,
                   1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1,
                   1, 1, 1, 1, 0,
                   1, 0, 0, 0, 0,
                   1, 0, 0, 0, 0,
                   1, 0, 0, 0, 0, ]

        letterQ = [0, 1, 1, 1, 0,
                   1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1,
                   1, 0, 1, 0, 1,
                   1, 0, 0, 1, 0,
                   0, 1, 1, 0, 1, ]

        letterR = [1, 1, 1, 1, 0,
                   1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1,
                   1, 1, 1, 1, 0,
                   1, 0, 1, 0, 0,
                   1, 0, 0, 1, 0,
                   1, 0, 0, 0, 1, ]

        letterS = [0, 1, 1, 1, 0,
                   1, 0, 0, 0, 1,
                   0, 1, 0, 0, 0,
                   0, 0, 1, 0, 0,
                   0, 0, 0, 1, 0,
                   1, 0, 0, 0, 1,
                   0, 1, 1, 1, 0, ]

        letterT = [1, 1, 1, 1, 1,
                   0, 0, 1, 0, 0,
                   0, 0, 1, 0, 0,
                   0, 0, 1, 0, 0,
                   0, 0, 1, 0, 0,
                   0, 0, 1, 0, 0,
                   0, 0, 1, 0, 0, ]

        letterU = [1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1,
                   0, 1, 1, 1, 0, ]

        letterV = [1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1,
                   0, 1, 0, 1, 0,
                   0, 0, 1, 0, 0, ]

        letterW = [1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1,
                   1, 0, 1, 0, 1,
                   1, 1, 0, 1, 1,
                   1, 0, 0, 0, 1, ]

        letterX = [1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1,
                   0, 1, 0, 1, 0,
                   0, 0, 1, 0, 0,
                   0, 1, 0, 1, 0,
                   1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1, ]

        letterY = [1, 0, 0, 0, 1,
                   1, 0, 0, 0, 1,
                   0, 1, 0, 1, 0,
                   0, 0, 1, 0, 0,
                   0, 0, 1, 0, 0,
                   0, 0, 1, 0, 0,
                   0, 0, 1, 0, 0, ]

        letterZ = [1, 1, 1, 1, 1,
                   0, 0, 0, 0, 1,
                   0, 0, 0, 1, 0,
                   0, 0, 1, 0, 0,
                   0, 1, 0, 0, 0,
                   1, 0, 0, 0, 0,
                   1, 1, 1, 1, 1, ]

        alphabet = [letterA, letterB, letterC, letterD, letterE, letterF, letterG, letterH,
                    letterI, letterJ, letterK, letterL, letterM, letterN, letterO, letterP,
                    letterQ, letterR, letterS, letterT, letterU, letterV, letterW, letterX,
                    letterY, letterZ]

        return alphabet

    def letterToVector(letter):
        vector = np.zeros(26)
        vector[np.where(letters == letter)] = 1
        return vector

    alphabet = np.asarray(get_alphabet())
    print('alphabet shape: ', alphabet.shape)
    print('A letter:')
    print(alphabet[0].reshape(7, 5))

    letters = np.asarray(
        ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
         'W',
         'X', 'Y', 'Z'])
    arrays = alphabet
    print('letters shape: ', letters.shape, ', arrays shape: ', arrays.shape)

    train_data = [[alphabet[i], letterToVector(letters[i])] for i in range(0, 26)]
    train_data = np.asarray(train_data, dtype=object)
    np.random.shuffle(train_data)
    train_data = np.concatenate((train_data,
                                 train_data))

    print(f'train data {train_data.shape}')

    x_train = np.asarray(list(train_data[:, 0]))
    y_train = np.asarray(list(train_data[:, 1]))

    print(y_train.shape, ' first label:', y_train[0])
    print(x_train.shape, ' first batch:', x_train[0])

    model = tf.keras.Sequential()
    model.add(layers.Dense(35, activation='tanh'))
    model.add(layers.Dense(10, activation='tanh'))
    model.add(layers.Dense(26, activation='softmax'))
    model.compile(optimizer='adam',
                  loss='mean_squared_error',
                  metrics=['accuracy'])

    model.fit(x_train, y_train, epochs=50, batch_size=1)

    x_test = x_train[:1]
    y_test = y_train[:1]
    print('expected result: \n', y_test)

    prediction = model.predict([x_test])
    prediction = np.round(prediction)
    print('prediction: \n', prediction)

    d1 = alphabet.shape[0]
    d2 = alphabet.shape[1]

    x = np.concatenate([alphabet,
                        alphabet,
                        alphabet + np.random.rand(d1, d2) * 0.1,
                        alphabet + np.random.rand(d1, d2) * 0.2])

    y = np.asarray([letterToVector(letter) for letter in letters.flatten()])
    y = np.concatenate([y, y, y, y])

    train_data = np.asarray([(x[i], y[i]) for i in range(0, len(x))])
    np.random.shuffle(train_data)

    x_train = np.asarray(list(train_data[:, 0]))
    y_train = np.asarray(list(train_data[:, 1]))

    print(y_train.shape, ' first label:', y_train[0])
    print(x_train.shape, ' first batch:', x_train[0])

    model = tf.keras.Sequential()
    model.add(layers.Dense(35, activation='tanh'))
    model.add(layers.Dense(10, activation='tanh'))
    model.add(layers.Dense(26, activation='softmax'))
    model.compile(optimizer='adam',
                  loss='mean_squared_error',
                  metrics=['accuracy'])
    model.fit(x_train, y_train, epochs=50, batch_size=1)

    new_model = tf.keras.Sequential()
    new_model.add(layers.Dense(35, activation='tanh'))
    new_model.add(layers.Dense(10, activation='tanh'))
    new_model.add(layers.Dense(10, activation='tanh'))
    new_model.add(layers.Dense(26, activation='softmax'))
    new_model.compile(optimizer='adam',
                      loss='mean_squared_error',
                      metrics=['accuracy'])
    new_model.fit(x_train, y_train, epochs=50, batch_size=1)

    x_test = x_train[:1]
    y_test = y_train[:1]
    print('expected result: \n', y_test)

    prediction = new_model.predict([x_test])
    prediction = np.round(prediction)
    print('prediction: \n', prediction)

    # эффективность
    first_errors = deque()
    second_errors = deque()

    y_test = np.asarray([letterToVector(letter) for letter in letters.flatten()])
    x = alphabet
    d1 = alphabet.shape[0]
    d2 = alphabet.shape[1]

    noise = np.linspace(0, 1, num=100)
    for i in range(0, 100):
        x_test = alphabet + np.random.rand(d1, d2) * noise[i]

        _, val_accuracy = model.evaluate(x_test, y_test)
        first_errors.append(1 - val_accuracy)

        _, val_accuracy = new_model.evaluate(x_test, y_test)
        second_errors.append(1 - val_accuracy)

    plt.plot(noise, first_errors, label='trained two-layer')
    plt.plot(noise, second_errors, label='trained tree-layer')
    plt.grid()
    plt.title('Error depending on the noise level')
    plt.legend()
    plt.xlabel('noise level')
    plt.ylabel('error (0.5 = 50%)')
    plt.show()


def russian():
    def plotchar(i):
        (plt.imshow(i.reshape(7, 5)))
        plt.show()

    def max_err(nn, train, err):
        c = np.zeros((32, 32))
        for i in range(1000):
            c += confusion_matrix(target.argmax(axis=1),
                                  nn.predict(train + np.random.normal(0, err, train.shape)).argmax(axis=1))
        return 1 - np.min(np.diag(c)) / 1000.0


    rus_letters = pd.read_csv("русский_пиксельный_алфавит.csv")
    rus_vovels = rus_letters[rus_letters.value.isin(['А', 'Е', 'И', 'О', 'У', 'Ы', 'Э', 'Ю', 'Я'])].drop("value",
                                                                                                         axis=1)
    rus_letters = rus_letters.drop("value", axis=1)

    plotchar(rus_vovels.values[1])

    train = rus_letters.values
    target = np.eye(32)
    clf = nn.MLPClassifier(hidden_layer_sizes=(10,),
                           activation='logistic',
                           max_iter=400000,
                           alpha=1e-4,
                           solver='sgd',
                           tol=1e-2,
                           random_state=1,
                           learning_rate_init=.1,
                           n_iter_no_change=10000)
    clf.fit(train, target)
    clf.predict(train)

    err = 0.2
    noise_train = train + np.random.normal(0, err, train.shape)

    plotchar(noise_train[5])

    clf3 = nn.MLPClassifier(hidden_layer_sizes=(15, 10),
                            activation='logistic',
                            max_iter=400000,
                            alpha=1e-4,
                            solver='sgd',
                            tol=1e-2,
                            random_state=1,
                            learning_rate_init=.1,
                            n_iter_no_change=10000)
    clf3.fit(train, target)
    clf3.predict(train + np.random.normal(0, err, train.shape))

    clf1err = []
    clf2err = []
    terr = np.arange(0, 1, 0.05)
    for i in terr:
        clf1err.append(max_err(clf, train, i))
        clf2err.append(max_err(clf3, train, i))

    plt.plot(terr, clf1err)
    plt.plot(terr, clf2err)
    plt.grid()
    plt.xlabel('noise level')
    plt.ylabel('error')
    plt.legend(['two-layer', 'tree-layer'])
    plt.show()

russian()