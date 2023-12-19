#include <bits/stdc++.h>
#include <fstream>
#include <algorithm> 
using namespace std;

void knapsack(int n, double w[], double p[], double capacity, int idx[])
{
    double result[40010], totalProfit = 0;
    int i;
    double remainingCapacity = capacity;

    for (i = 0; i < n; i++)
        result[i] = 0.0;

    for (i = 0; i < n; i++)
    {
        if (w[i] > remainingCapacity)
            break;
        else
        {
            result[i] = 1.0;
            totalProfit += p[i];
            remainingCapacity -= w[i];
        }
    }

    if (i < n)
        result[i] = remainingCapacity / w[i];

    totalProfit += result[i] * p[i];

    // for (i = 0; i < n; i++)
    // {
    //     cout << "index: ";
    //     cout << idx[i] << "\t\t";
    //     cout << "Ammaunt: ";
    //     cout <<  << "\t\t";
    //     cout << "Weight : ";
    //     cout << w[i] << "\t\t";
    //     cout << "Profit  : ";
    //     cout << p[i] << "\t\t";
    //     cout << "Ratio:" << p[i] / w[i] << "\n";
    // }
    int c=0;

    
while(c<n){
 
    
    for(i=0; i<n; i++){
        if(idx[i]==c){
            cout<< p[i] / w[i] <<"\t\t\t";
            c++;
            break;
        }
    }}
    
  c=0;

  cout<<endl;
while(c<n){
 
    
    for(i=0; i<n; i++){
        if(idx[i]==c){
            cout<<result[i]<<"\t\t\t";
            c++;
            break;
        }
    }}
    

    cout << "\nMaximum profit is: " << totalProfit << endl;
}

int main()
{
    ifstream inputFile("knapsack.txt");
    int n = 21100;
    double weights[n + 5], profits[n + 5], knapsackCapacity;
    int num, i, j, idx[n + 5];
    double ratios[n + 5];

    inputFile >> num;

    for (i = 0; i < num; i++)
    {
        idx[i] = i;
    }

    for (i = 0; i < num; i++)
    {
        inputFile >> weights[i];
    }

    for (i = 0; i < num; i++)
    {
        inputFile >> profits[i];
    }

    cout << "\nEnter the capacity of knapsack: ";
    cin >> knapsackCapacity;

    for (i = 0; i < num; i++)
    {
        ratios[i] = profits[i] / weights[i];
    }

    for (i = 0; i < num; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (ratios[i] < ratios[j])
            {
                swap(ratios[i], ratios[j]);
                swap(weights[i], weights[j]);
                swap(profits[i], profits[j]);
                swap(idx[i], idx[j]);
            }
        }
    }

    knapsack(num, weights, profits, knapsackCapacity, idx);
    inputFile.close();
}
