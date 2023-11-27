#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int n, a, b;
        cin >> n >> a >> b;

        if (n % a <= (n/a)*min((b-a), n%a))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
