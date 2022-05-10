#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>

using namespace std;
using namespace chrono;

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

static void fillVectorInt(vector<int>&v, unsigned long long n)
{
    for (unsigned long long i = 0; i < n; i++)
    {
        v.emplace_back(rand());
    }
}


int main()
{
    high_resolution_clock::time_point t1, t2;
    vector<int> v;
    long long number;
    long long tries = 1;
    for (int i = 1; i <= 50; i++)
    {
        number = pow(10, i);
        long long duration_total = 0;
        for (int j = 0; j < tries; j++)
        {
            fillVectorInt(v, number);

            t1 = high_resolution_clock::now();
            insertionSort(&v[0], v.size());
            t2 = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(t2 - t1).count();
            duration_total += duration;

            v.clear();
        }
        long long int average_duration = duration_total / tries;
        cout << number << " : " << average_duration << "us" << endl;;
    }
    cout << endl;
    return 0;
}