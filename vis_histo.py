import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

x1 = pd.read_csv("cmake-build-debug/Part_init.csv", names=('x', 'y', 'z'))
x2 = pd.read_csv("cmake-build-debug/Part_fin.csv", names=('x', 'y', 'z'))

# x1 = x1.T
# x1 = x1.values
# x2 = x2.T
# x2 = x2.values

plt.hist(x1['y'].values, bins = 100)
plt.show()

plt.hist(x2['y'].values, bins = 100)
plt.show()