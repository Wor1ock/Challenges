#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> numbers(N);
    for (int i = 0; i < N; ++i)
        numbers[i] = i + 1;

    do
    {
        for (int i = 0; i < N; ++i)
            cout << numbers[i];
        cout << endl;
    } while (next_permutation(numbers.begin(), numbers.end()));

    return 0;
}