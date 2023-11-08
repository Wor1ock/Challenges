#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for (int i; i < n; ++i)
        cin >> vec[i];

    int l, r, min;
    for (int i = 0; i < k; ++i)
    {
        cin >> l >> r;
        min = vec[l];
        bool temp = true;
        for (int j = l; j < r + 1; ++j)
        {
            if (vec[j] > min)
            {
                cout << vec[j] << "\n";
                temp = false;
                break;
            }
            else if (vec[j] < min)
            {
                cout << min << "\n";
                temp = false;
                break;
            }
        }
        if (temp)
            cout << "NOT FOUND\n";
    }
    return 0;
}