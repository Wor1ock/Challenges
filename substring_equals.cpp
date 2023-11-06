#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    if (str == "")
        return 0;

    int n;
    cin >> n;

    int a, b, c;
    bool temp;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b >> c;
        temp = true;
        while (a--)
        {
            if (str[b++] != str[c++])
            {
                temp = false;
                break;
            }
        }
        if (temp)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}