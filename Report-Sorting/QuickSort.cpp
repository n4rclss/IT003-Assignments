#include <bits/stdc++.h>
using namespace std;

// Partition function for QuickSort
int partition(vector<double>& arr, int left, int right) {
    int pivot = right;
    int stored_pivot = left;

    for (int index = left; index < right; ++index) {
        if (arr[index] < arr[pivot])
        {
            swap(arr[index], arr[stored_pivot]);
            stored_pivot++;
        }
    }
    swap(arr[pivot], arr[stored_pivot]);
    return stored_pivot;
}

// QuickSort function
void QuickSort(vector<double>& arr, int left, int right) {
    if (left >= right)
        return;
    int pi = partition(arr, left, right);
    QuickSort(arr, left, pi - 1);
    QuickSort(arr, pi + 1, right);
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
    for (int i = 9; i >=0 ; i--) {
        input_arr.clear();
        string filename = "./my_dataset/data" + to_string(i + 1) + ".txt";
        ifstream file(filename);
        double value;
        while (file >> value)
            input_arr.push_back(value);
        file.close();
        clock_t start = clock();
        QuickSort(input_arr, 0, input_arr.size() - 1);
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

