#include <iostream>
#include<fstream>
#include <bits/stdc++.h>
#include <ctime>
using namespace std;

void MaxMin(vector<int>& a, int i, int j, int& max, int& min) {
    if (i == j) {
        max = min = a[i];
    } else if (i == j - 1) {
        if (a[i] < a[j]) {
            max = a[j];
            min = a[i];
        } else {
            max = a[i];
            min = a[j];
        }
    } else {
        int mid = (i + j) / 2;
        int max1, min1, max2, min2;
        MaxMin(a, i, mid, max1, min1);
        MaxMin(a, mid + 1, j, max2, min2);

        if (max1 > max2) max = max1;
        else max = max2;

        if (min1 < min2) min = min1;
        else min = min2;
    }
}


int main()
{

    clock_t start_time = clock();
      clock_t end_time = clock();
    fstream f;
    f.open("random.txt");

     cout<<"Input Range"<<endl;
    int n;
    cin>>n;
    vector <int> a(n);
    int i=0;
     while (i < n && f >> a[i])
    {
        i++;
    }
    int max,min;
     start_time = clock();
    MaxMin(a, 0, a.size() - 1, max, min);
     end_time = clock();
     double binarySearchTime = end_time - start_time;
    cout<<"Maximum is: "<<max<<"    Minimum is: "<<min<<endl;
cout<<"Time needed: "<<binarySearchTime<<endl;


int mx, mm;
mx=INT_MIN;
mm=INT16_MAX;

  start_time = clock();
for(i=0; i<n; i++){
    if(a[i]>mx){
        mx=a[i];
    }
}
for(i=0; i<n; i++){
    if(a[i]<mm){
        mm=a[i];
    }
}
   end_time = clock();
    binarySearchTime = end_time - start_time;
    cout<<"For brute force:"<<endl;
    cout<<"Maximum is: "<<max<<"    Minimum is: "<<min<<endl;
    cout<<"Time needed: "<<binarySearchTime<<endl;
 return 0;
}