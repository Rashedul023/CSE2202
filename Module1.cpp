#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

// Function prototypes
void bubbleSort(int data[], int size);
void selectionSort(int data[], int size);
void insertionSort(int data[], int size);
void printArray(const int data[], int size);

int main() {
    int maxSize;
    cout << "Enter the maximum number of data: ";
    cin >> maxSize;

    int* data = new int[maxSize];

    string fileName = "MergeData.txt"; // Assuming the file name is MergeData.txt
    int size, choice;

    // Read data from a file
    ifstream inputFile(fileName);
    if (!inputFile) {
        cerr << "Error opening file. Exiting program." << endl;
        delete[] data;
        return 1;
    }

    int value, index = 0;
    while (inputFile >> value && index < maxSize) {
        data[index++] = value;
    }

    size = index;

    // Menu for sorting options
    do {
        cout << "\nSorting Menu:" << endl;
        cout << "1. Bubble Sort" << endl;
        cout << "2. Selection Sort" << endl;
        cout << "3. Insertion Sort" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        clock_t start, end;
        double cpu_time_used;

        switch (choice) {
            case 1:
                start = clock();
                bubbleSort(data, size);
                end = clock();
                cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
                cout << "Sorted using Bubble Sort:" << endl;
                //printArray(data, size);
                cout << "Time taken: " << cpu_time_used << " seconds" << endl;
                break;
            case 2:
                start = clock();
                selectionSort(data, size);
                end = clock();
                cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
                cout << "Sorted using Selection Sort:" << endl;
                //printArray(data, size);
                cout << "Time taken: " << cpu_time_used << " seconds" << endl;
                break;
            case 3:
                start = clock();
                insertionSort(data, size);
                end = clock();
                cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
                cout << "Sorted using Insertion Sort:" << endl;
                //printArray(data, size);
                cout << "Time taken: " << cpu_time_used << " seconds" << endl;
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        }
    } while (choice != 4);

    delete[] data;
    return 0;
}

void bubbleSort(int data[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (data[j] > data[j + 1]) {
                // Swap elements
                swap(data[j], data[j + 1]);
            }
        }
    }
}

void selectionSort(int data[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (data[j] < data[minIndex]) {
                minIndex = j;
            }
        }
        // Swap elements
        swap(data[i], data[minIndex]);
    }
}

void insertionSort(int data[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = data[i];
        int j = i - 1;

        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            --j;
        }

        data[j + 1] = key;
    }
}

void printArray(const int data[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;
}
