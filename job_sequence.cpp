#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b) {
    return (a.profit > b.profit);
}

void jobSequencing(int n, Job jobs[], int sequence[]) {
    sort(jobs, jobs + n, compare);

    vector<bool> slot(n, false);

    for (int i = 0; i < n; i++) {
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                sequence[j] = jobs[i].id;
                slot[j] = true;
                break;
            }
        }
    }
}

int main() {
    ifstream inputFile("job_sequence.txt");
    int n;
    inputFile >> n;

    Job jobs[n];

    for (int i = 0; i < n; i++) {
        jobs[i].id = i + 1;
        inputFile >> jobs[i].profit;
    }

    for (int i = 0; i < n; i++) {
        inputFile >> jobs[i].deadline;
    }

    int sequence[n];
    jobSequencing(n, jobs, sequence);

    cout << "Job Sequence: ";
    for (int i = 0; i < n; i++) {
        if (sequence[i] != 0) {

            if(sequence[i] <1  || sequence[i]>n) break;
            cout << sequence[i] << " ";
            
            
        }
    }

    inputFile.close();
    return 0;
}
