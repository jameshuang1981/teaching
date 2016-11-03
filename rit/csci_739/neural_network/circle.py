
from itertools import product

import numpy as np
import matplotlib.pyplot as plt

from sklearn import datasets
from sklearn.neural_network import MLPClassifier
from sklearn.linear_model import LinearRegression
from sklearn.linear_model import LogisticRegression

if __name__ == "__main__":
    # load data
    # digits = datasets.load_digits()
    # X = digits.data[:, [0, 2]]
    # y = digits.target
    # print(X)
    # print(y)
    X = [[0., 0.], [0., 1.], [1., 0.], [1., 1.]]
    y = [0, 1, 1, 0]

    # fit data
    # clf_lin = LinearRegression()
    # clf_lin.fit(X, y)
    clf_log = LogisticRegression()
    clf_log.fit(X, y)
    clf_nn = MLPClassifier()
    clf_nn.fit(X, y)

    # Plot decision regions
    # x_min, x_max = X[:, 0].min() - 1, X[:, 0].max() + 1
    # y_min, y_max = X[:, 1].min() - 1, X[:, 1].max() + 1
    x_min, x_max = min([x[0] for x in X]) - 1, max([x[0] for x in X]) + 1
    y_min, y_max = min([x[1] for x in X]) - 1, max([x[1] for x in X]) + 1
    xx, yy = np.meshgrid(np.arange(x_min, x_max, 0.1), np.arange(y_min, y_max, 0.1))

    f, axarr = plt.subplots(2, 1, sharex='col', sharey='row', figsize=(10, 8))

    for idx, clf, tt in zip([[0], [1]],
                           # product([0], [0, 1]),
                           # [clf_log, clf_log, clf_nn, clf_nn],
                           [clf_log, clf_nn],
                           # ['linear regression', 'logistic regression','probit regression', 'neural network']):
                           ['logistic regression', 'neural network']):
                           Z = clf.predict(np.c_[xx.ravel(), yy.ravel()])
                           Z = Z.reshape(xx.shape)

                           axarr[idx[0]].contourf(xx, yy, Z, alpha = 0.5)
                           # axarr[idx[0], idx[1]].scatter(X[:, 0], X[:, 1], c=y, alpha=0.8)
                           axarr[idx[0]].scatter([x[0] for x in X], [x[1] for x in X])
                           axarr[idx[0]].set_title(tt)

    plt.show()
