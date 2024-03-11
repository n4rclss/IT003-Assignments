import time
import sys

sys.setrecursionlimit(99999999)

# Partition function for QuickSort
def partition(arr, left, right):
    pivot = right
    stored_pivot = left

    for index in range(left, right):
        if arr[index] < arr[pivot]:
            arr[index], arr[stored_pivot] = arr[stored_pivot], arr[index]
            stored_pivot += 1

    arr[pivot], arr[stored_pivot] = arr[stored_pivot], arr[pivot]
    return stored_pivot

# QuickSort function
def QuickSort(arr, left, right):
    if left >= right:
        return
    pi = partition(arr, left, right)
    QuickSort(arr, left, pi - 1)
    QuickSort(arr, pi + 1, right)

# Checking function to validate sorting
def Checking(arr, k):
    test_file = "./my_testcase/test" + str(k + 1) + ".txt"
    with open(test_file, 'r') as file:
        sorted_arr = [float(line.strip()) for line in file]

    return arr == sorted_arr

def main():
    for i in range(9, -1, -1):
        input_arr = []
        filename = "./my_dataset/data" + str(i + 1) + ".txt"
        with open(filename, 'r') as file:
            input_arr = [float(line.strip()) for line in file]

        start = time.time()
        QuickSort(input_arr, 0, len(input_arr) - 1)
        end = time.time()
        print("Sort data {}: Done".format(i + 1))
        print("Time taken: {:.2f} ms".format((end - start) * 1000))

        if Checking(input_arr, i):
            print("Correct!")
        else:
            print("Wrong!")

if __name__ == "__main__":
    main()
