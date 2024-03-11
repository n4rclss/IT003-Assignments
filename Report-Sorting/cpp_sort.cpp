#include <bits/stdc++.h>
using namespace std;

int main() {
    for (int i=0; i<=9; i++){
        string filename = "./my_dataset/data" + to_string(i+1) + ".txt";
        ifstream file(filename); 
        vector<double> numbers; 
        string line;
        while (getline(file, line)) { 
            double num = atof(line.c_str());
            numbers.push_back(num); 
        }
        file.close(); 
        clock_t start = clock();
        sort(numbers.begin(), numbers.end());
        clock_t end = clock();
        cout << "Sort data " << i + 1 << ": Done\n";
        cout << "Time taken: " << (double(end - start) / CLOCKS_PER_SEC) * 1000 << endl;
    }
    return 0;
}
