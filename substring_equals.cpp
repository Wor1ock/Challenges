#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int n;
    cin >> n;

    int a, b, c;
    bool *temp = new bool[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b >> c;
        temp[i] = true;
        while (a--)
        {
            if (str[b++] != str[c++])
                temp[i] = false;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (temp[i])
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}