#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    
    srand(time(NULL));

    
    ofstream outputFile("random.txt");

    
    for (int i = 0; i < 500000; i++) {
        outputFile << rand() << endl;
    }

    
    outputFile.close();

    return 0;
}