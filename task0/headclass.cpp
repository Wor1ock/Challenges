#include <iostream>
#include <vector>

using namespace std;

void dissatisfaction_calc(const vector<int> rates, vector<int> &vec)
{
    int size = vec.size();
    int sum = 0;
    for (int i = 0; i < size; ++i)
    {
        vec[i] = rates[i] * i - sum;
        sum += rates[i];
    }

    sum = 0;
    for (int i = 0, j = size - 1; j > -1; ++i, --j)
    {
        vec[j] += sum - rates[j] * i;
        sum += rates[j];
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> rates(n);
    vector<int> frustration(n);

    for (int i = 0; i < n; ++i)
        cin >> rates[i];

    dissatisfaction_calc(rates, frustration);
    for (int i = 0; i < n; ++i)
        cout << frustration[i] << " ";

    return 0;
}