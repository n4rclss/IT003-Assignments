#include <bits/stdc++.h>
using namespace std;

//Build a heap <--------------------------------------------------------------------------------------------------.
//Repeat until the heap contains only one element:                                                                |
//      Swap the root element of the heap (the largest) with the last element of the heap.                        |
//      Remove the last element                                                                                   |
//      Heapify the remaining elements of the heap. --------------------------------------------------------------'

void Heapify(vector<double>& arr, int begin_node, int end_node)
{
    int parent_node = begin_node,
        left_child_node = 2 * parent_node + 1,
        right_child_node = 2 * parent_node + 2;

    if (left_child_node <= end_node && arr[left_child_node] > arr[parent_node])
        parent_node = left_child_node;
    if (right_child_node <= end_node && arr[right_child_node] > arr[parent_node])
        parent_node = right_child_node;

    if (parent_node != begin_node){
        swap(arr[parent_node], arr[begin_node]);
        Heapify(arr, parent_node, end_node);
    }
}

void HeapSort(vector<double>& arr, int N)  //N = size(arr) - 1
{
    //Build a heap for a input array (For the first time)
    // i = ((N - 1) - 1) / 2 = N/2 - 1 (if N = size(arr))
    for (int i = (N-1)/2; i >= 0; i--){
        Heapify(arr, i, N);
    }

    //Repeat until the heap remain 1 element (i>0)
    for (int i = N; i > 0; i--){
        //Swap: Move the root node (arr[0]) to the last element node (arr[i])
        swap(arr[0], arr[i]);
        //Heapify again (except the a[i] as correct-located element)
        Heapify(arr, 0, i - 1);
    }
}

// Checking function to validate sorting
bool Checking(vector<double>& arr, int k) {
    string test_file = "./my_testcase/test" + to_string(k + 1) + ".txt";
    vector<double> sorted_arr;
    ifstream file(test_file);
    double value;
    while (file >> value)
        sorted_arr.push_back(value);
    file.close();
    if (arr == sorted_arr)
        return true;
    else
        return false;
}

int main() {
    vector<double> input_arr;
    for (int i = 0; i <= 9; ++i) {
        input_arr.clear();
        string filename = "./my_dataset/data" + to_string(i + 1) + ".txt";
        ifstream file(filename);
        double value;
        while (file >> value)
            input_arr.push_back(value);
        file.close();
        clock_t start = clock();
        HeapSort(input_arr, input_arr.size() - 1);
        clock_t end = clock();
        cout << "Sort data " << i + 1 << ": Done\n";
        cout << "Time taken: " << (double(end - start) / CLOCKS_PER_SEC) * 1000 << endl;
        if (Checking(input_arr, i))
            cout << "Correct!\n";
        else
            cout << "Wrong!\n";
    }
    return 0;
}