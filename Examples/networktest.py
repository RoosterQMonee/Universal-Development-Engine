import UDE.ML as ML
from network import *
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

np.set_printoptions(threshold=np.inf)
data = pd.read_csv('./UDE/Utils/Datasets/csv/msint.csv')

data.head()

data = np.array(data)
m, n = data.shape
np.random.shuffle(data)

data_dev = data[0:1000].T
Y_dev = data_dev[0]
X_dev = data_dev[1:n]
X_dev = X_dev / 255.

data_train = data[1000:m].T
Y_train = data_train[0]
X_train = data_train[1:n]
X_train = X_train / 255.
_,m_train = X_train.shape

W1 = np.array(W1)
b1 = np.array(b1)
W2 = np.array(W2)
b2 = np.array(b2)

for test in range(1):
    t1 = ML.test_prediction(test, X_train, Y_train, W1, b1, W2, b2)

    plt.gray()
    plt.imshow(t1, interpolation='nearest')
    plt.show()
