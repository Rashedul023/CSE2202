#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    const int arraySize = 50000;
    int data[arraySize];

   
    srand(time(nullptr));

    
    data[0] = rand() % 100; 
    for (int i = 1; i < arraySize; i++) {
        
        data[i] = data[i - 1] + (rand() % 10 + 1); 
    }

   
    ofstream outputFile("5.txt");

   
    if (!outputFile.is_open()) {
        cout << "Error: Unable to open the file for writing." << endl;
        return 1;
    }

   
    for (int i = 0; i < arraySize; i++) {
        outputFile << data[i] << endl;
    }

    
    outputFile.close();

    return 0;
}
