#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, n;
    cin >> a >> b >> n;

    if (a - 1 > ceil(b / n))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
