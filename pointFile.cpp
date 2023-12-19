#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Point {
    int x, y;
};

int main() {
    srand(time(0));

    ofstream outputFile("points.txt");
    if (!outputFile.is_open()) {
        cerr << "Error opening output file." << endl;
        return 1;
    }

    int n = 10; // Change this to the number of points you want

    outputFile << n << endl;
    for (int i = 0; i < n; i++) {
        outputFile << rand() % 100 << " " << rand() % 100 << endl;
    }

    outputFile.close();

    cout << "File 'points.txt' generated successfully." << endl;

    return 0;
}
