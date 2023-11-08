#include <iostream>

using namespace std;

int euclidean_gcd(int m, int n)
{
    int a = max(m, n);
    int b = min(m, n);
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int m = a * d + b * c;
    int n = b * d;

    int temp = euclidean_gcd(m, n);
    cout << m / temp << " " << n / temp;
    return 0;
}