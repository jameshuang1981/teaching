
# modules
import sys
import csv
import numpy as np
import matplotlib.pyplot as plt

from sklearn.linear_model import LogisticRegression
from sklearn.neural_network import MLPClassifier
from itertools import product

if __name__ == "__main__":
    # get parameters
    data_file = sys.argv[1]
    header = sys.argv[2]

    # load data
    X = []
    y = []
    with open(data_file, 'r') as f:
        spamreader = list(csv.reader(f, delimiter = ','))
        start = 1 if header else 0
        for i in range(start, len(spamreader)):
            line = spamreader[i]
            n = len(line)
            x = []
            for i in range(0, n - 1):
                x.append(float(line[i].strip()))
            X.append(x)
            y.append(int(line[n - 1].strip()))

    # fit data
    clf_log = LogisticRegression()
    clf_log.fit(X, y)
    clf_nn = MLPClassifier()
    clf_nn.fit(X, y)

    # Plot decision regions
    x_min, x_max = min([x[0] for x in X]) - 1, max([x[0] for x in X]) + 1
    y_min, y_max = min([x[1] for x in X]) - 1, max([x[1] for x in X]) + 1
    xx, yy = np.meshgrid(np.arange(x_min, x_max + 0.1, 0.1), np.arange(y_min, y_max + 0.1, 0.1))

    for clf, tt in zip([clf_log, clf_nn], ['logistic regression', 'neural network']):
        # get the class
        Z = clf.predict(np.c_[xx.ravel(), yy.ravel()])
        Z = Z.reshape(xx.shape)

        # plot contourf
        plt.figure()
        plt.contourf(xx, yy, Z, alpha = 0.5)
        plt.scatter([x[0] for x in X], [x[1] for x in X], c = y, s = 100, alpha = 0.5)
        plt.title(tt)
        plt.xlim(-1, 2)
        plt.ylim(-1, 2)
        plt.show()
