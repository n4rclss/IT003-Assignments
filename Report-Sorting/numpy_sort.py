import numpy as np
from time import time

for i in range(0, 10):
    filename = "./my_dataset/data" + str(i+1) + ".txt"
    with open(filename, 'r') as file:
        unsorted_arr = np.loadtxt(filename)
    start = time()
    sorted_arr = np.sort(unsorted_arr)
    end = time()
    print("Data {}: Done".format(i+1))
    print("Time taken: {}".format((end - start)))
    