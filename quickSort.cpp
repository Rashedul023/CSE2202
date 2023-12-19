#include <iostream>
#include <fstream>
#include <ctime>

long long int a[400000],m,p;


using namespace std;

void quickSort(int low, int high);

int partition(int low, int high);

int main()
{
    ifstream inputFile("MergeData.txt");

    if (!inputFile.is_open())
    {
        cout << "Error opening file" << endl;
        return 1;
    }

    long long int num, i, max;
    cout << "How many numbers?" << endl;
    cin >> max;
    m=max;
  
    clock_t time1, time2, Time;

    for (int i = 0; i < max; i++)
    {
        inputFile >> a[i];
    }
        for ( i = 0; i < max; i++)
    {
        cout << a[i] << " ";
    }
    cout<<endl;


    time1 = clock();
    quickSort(0, max - 1);
    time2 = clock();
    Time = time2 - time1;

    cout << "Time taken for Quick Sort: " << Time << " milliseconds" << endl;

    // for (int i = 0; i < max; i++)
    // {
    //     cout << a[i] << endl;
    // }

    inputFile.close();

    return 0;
}

void quickSort(int low, int high)
{
    if (low < high)
    {
        int pi = partition(low, high);



        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

int partition(int low, int high)
{
    int pivot = a[high];
    p= pivot;
    
   
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    cout<<"Pivot is: " <<p<<endl;
     for (int i = 0; i < m; i++)
    {
        cout << a[i]<<" ";
    }
    cout<<endl;
    return (i + 1);
}
