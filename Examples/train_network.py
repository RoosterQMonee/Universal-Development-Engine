import UDE
import numpy as np
import pandas as pd

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

W1, b1, W2, b2 = UDE.ML.gradient_descent(m, X_train, Y_train, 0.10, 2500)

with open("./network.py", "w") as network_data:
    network_data.write(f"""
    W1 = {str([item for item in W1]).replace("), array(", ",")}
    b1 = {str([item for item in b1]).replace("), array(", ",")}
    W2 = {str([item for item in W2]).replace("), array(", ",")}
    b2 = {str([item for item in b2]).replace("), array(", ",")}
    """)
