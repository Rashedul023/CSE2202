#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Job {
    int id;       // Using integers for job IDs
    int deadline;
    int profit;
};

int main() {
    srand(time(nullptr));  // Seed for random number generation
    ofstream outputFile("job_sequence.txt");

    if (!outputFile) {
        cerr << "Error creating file!" << endl;
        return 1;
    }

    int numJobs = 100000;
    outputFile << numJobs << endl;

    for (int i = 0; i < numJobs; ++i) {
        int jobId = i + 1;  // Job IDs start from 1
        int deadline = rand() % 10 + 1;  // Random deadline from 1 to 10
        int profit = rand() % 100 + 1;  // Random profit from 1 to 100

        outputFile << jobId << " " << deadline << " " << profit << endl;
    }

    outputFile.close();

    cout << "Job sequence file with 100,000 entries created successfully." << endl;

    return 0;
}
