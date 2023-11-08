#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

void printArray(const vector<string> &arr)
{
    int size = arr.size();
    for (size_t i = 0; i < size; ++i)
    {
        cout << arr[i];
        if (i < size - 1)
            cout << ", ";
    }
    cout << endl;
}

void printBuckets(const vector<vector<string>> &buckets, int phase)
{
    cout << "Phase " << phase << endl;
    for (int i = 0; i < buckets.size(); ++i)
    {
        cout << "Bucket " << i << ": ";
        if (buckets[i].empty())
            cout << "empty\n";
        else
        {
            for (int j = 0; j < buckets[i].size(); ++j)
            {
                cout << buckets[i][j];
                if (j < buckets[i].size() - 1)
                    cout << ", ";
            }
            cout << endl;
        }
    }
    cout << "**********\n";
}

void radixSort(vector<string> &arr, int m)
{
    for (int i = m - 1; i >= 0; --i)
    {
        vector<vector<string>> buckets(10);
        for (const string &s : arr)
        {
            int digit = s[i] - '0';
            buckets[digit].push_back(s);
        }
        printBuckets(buckets, m - i);
        int index = 0;
        for (const auto &bucket : buckets)
            for (const string &s : bucket)
                arr[index++] = s;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> vec(n);
    for (int i = 0; i < n; ++i)
        cin >> vec[i];

    cout << "Initial array:" << endl;
    printArray(vec);
    cout << "**********\n";

    int m = vec[0].size();
    radixSort(vec, m);

    cout << "Sorted array:" << endl;
    printArray(vec);

    return 0;
}
