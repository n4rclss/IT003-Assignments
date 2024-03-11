import random
import os
from time import time 

count = 10
directory_path_1 = "my_dataset"
directory_path_2 = "my_testcase"

if not os.path.exists(directory_path_1):
    os.makedirs(directory_path_1)
if not os.path.exists(directory_path_2):
    os.makedirs(directory_path_2)

start = time()
while count > 0:
    data = []

    for i in range(10**6):
        num = random.uniform(-(10**3), 10**3)
        data.append(round(num, 3))
        
    if count == 1:
        data = sorted(data)
    if count == 2:
        data = sorted(data, reverse=True)
    
    filename1 = "data" + str(count)+ ".txt"
    file_path_1 = os.path.join(directory_path_1, filename1)

    with open(file_path_1, 'w') as f:
        f.write('\n'.join(map(str, data)))
    data = sorted(data)

    filename2 = "test" + str(count) + ".txt"
    file_path_2 = os.path.join(directory_path_2, filename2)

    with open(file_path_2, 'w') as f:
        f.write('\n'.join(map(str, data)))
    count -= 1

print("Dataset and TestCase Generated Successfully!")
print("Time taked: {}".format(time() - start))