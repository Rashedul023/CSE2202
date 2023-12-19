#include <iostream>
#include <fstream>
#include <ctime>
#include <algorithm> 

using namespace std;

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    int step = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            cout << "Total step for Binary search: " << step << endl;
            return 1;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
        step++;
    }
    cout << "Total step for Binary search: " << step << endl;

    return 0;
}

int linearSearch(int arr[], int size, int target) {
    int step = 0;
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == target) {
            cout << "Total step for Linear search: " << step << endl;
            cout << "Index is: " << i << endl;
            return 1;
        }
        step++;
    }
    cout << "Total step for Linear search: " << step << endl;

    return 0;
}

int main() {
    ifstream inputFile("MergeData.txt");

   

    const int arraySize = 5000;
    int data[arraySize];
    int target;
    cout << "Please input target number: ";
    cin >> target;

    for (int i = 0; i < arraySize; i++) {
        inputFile >> data[i];
    }

    inputFile.close();

    // Sort the data array before performing binary search
    sort(data, data + arraySize);

    clock_t start_time = clock();



    
    int binaryResult = binarySearch(data, arraySize, target);
    clock_t end_time = clock();
    double binarySearchTime = end_time - start_time;


    cout<<"Total data: "<<arraySize<<endl;

    if (binaryResult == 1) {
        cout << "Binary Search: Found" << endl;
    } else {
        cout << "Binary Search: Not found" << endl;
    }

    cout << "Binary Search Time: " << binarySearchTime << " milliseconds" << endl;

    start_time = clock();
    int linearResult = linearSearch(data, arraySize, target);
    end_time = clock();
    double linearSearchTime = end_time - start_time;

    if (linearResult == 1) {
        cout << "Linear Search: Found" << endl;
    } else {
        cout << "Linear Search: Not found" << endl;
    }

    cout << "Linear Search Time: " << linearSearchTime << " milliseconds" << endl;

    return 0;
}
