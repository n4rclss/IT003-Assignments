#include <bits/stdc++.h>
using namespace std;

void Merge(vector<double>& arr, int left, int right, int mid)
{
    int left_size = mid - left + 1,
        right_size = right - mid;

    //Initialize temp arrays: Using this method (HeapAllocation) to delete after each recursion => Release the memory
    auto *left_arr = new double[left_size];
    auto *right_arr = new double[right_size];

    //Copy element to temp arrays
    for (int i = 0; i < left_size; i++)
        left_arr[i] = arr[left + i];
    for (int i = 0; i < right_size; i++)
        right_arr[i] = arr[mid + 1 + i];

    int index_merged_arr = left,
        index_left_arr = 0,
        index_right_arr = 0;

    //Merge the temp
    while (index_left_arr < left_size && index_right_arr < right_size)
    {
        if (left_arr[index_left_arr] <= right_arr[index_right_arr]){
            arr[index_merged_arr] = left_arr[index_left_arr];
            index_left_arr++;
        }
        else{
            arr[index_merged_arr] = right_arr[index_right_arr];
            index_right_arr++;
        }
        index_merged_arr++;
    }
    
    //If there are any elements of temp_left_arr => Merge
    for (int i = index_left_arr; i < left_size; i++){
        arr[index_merged_arr] = left_arr[i];
        index_merged_arr++;
    }
    
    //If there are any elements of temp_right_arr => Merge
    for (int i = index_right_arr; i < right_size; i++){
        arr[index_merged_arr] = right_arr[i];
        index_merged_arr++;
    }

    //Release memory
    delete[] left_arr;
    delete[] right_arr;   
}

void MergeSort(vector<double>& arr, int left, int right)
{
    if (left >= right)
        return;
    int mid = left + (right - left)/2;
    //Should be divided as [left,mid] and [mid+1,right] instead [left,mid-1] and [mid,right]
    MergeSort(arr, mid + 1, right);
    MergeSort(arr, left, mid);
    Merge(arr, left, right, mid);
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
        MergeSort(input_arr, 0, input_arr.size() - 1);
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