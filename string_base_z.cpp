#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> z_function(string s)
{
    int n = (int)s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int findBase(const string str)
{
    std::vector<int> z = z_function(str);
    int n = str.length();

    for (int i = 1; i < n; i++) {
        if (n % i == 0 && i + z[i] == n)
            return i;
    }

    return n;
}

int main()
{
    string str = "";
    cin >> str;

    int base = findBase(str);
    cout << base;
    return 0;
}