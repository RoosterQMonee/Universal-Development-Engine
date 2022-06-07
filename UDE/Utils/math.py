import numpy as np

class math:
    def softmax(x):
        return np.exp(x) / np.sum(np.exp(x), axis=0)

    def sigmoid(x):
        return 1 / (1 + np.exp(-x))

    def relu(x):
        return np.maximum(0, x)

    def softplus(x):
        return np.log(1 + np.exp(x))

    def leaky_relu(x, alpha=0.01):
        return np.maximum(alpha * x, x)

    def elu(x, alpha=0.01):
        return np.where(x > 0, x, alpha * (np.exp(x) - 1))
