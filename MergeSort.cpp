#include <iostream>
#include <fstream>
#include <ctime>
long long int b[400000], a[400000];

using namespace std;
void merging(int low, int mid, int high)
{
    int l1, l2, i;
    for (l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++)
    {
        if (a[l1] <= a[l2])
            b[i] = a[l1++];
        else
            b[i] = a[l2++];
    }
    while (l1 <= mid)
        b[i++] = a[l1++];
    while (l2 <= high)
        b[i++] = a[l2++];
    for (i = low; i <= high; i++)
        a[i] = b[i];
}
void sort(int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        sort(low, mid);
        sort(mid + 1, high);
        merging(low, mid, high);
    }
    else
    {
        return;
    }
}

int main()
{

    ifstream inputFile("MergeData.txt");

    if (!inputFile.is_open())
    {
        cout << "Error opening file" << endl;
        return 1;
    }

    long long int num, i, max;
    cout << "How may numbers?" << endl;
    cin >> max;
    clock_t time1, time2, Time;

    for (int i = 0; i < max; i++)
    {
        inputFile >> a[i];
    }
    // for (i = 0; i < max; i++)
    // {
    //     cout << a[i] << endl;
    // }

    time1 = clock();
    sort(0, max - 1);
    //cout << "After Sorting" << endl;

    time2 = clock();
    Time = time2 - time1;
    cout <<"time needed: "<< Time << endl;
    // for (int i = 0; i < max; i++)
    // {
        
    //     cout << a[i] << endl;
    // }
    

    inputFile.close();

    return 0;
}
