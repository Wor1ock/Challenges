#include <iostream>
#include <string>

using namespace std;

bool isPalindrom(string str)
{
    int size = str.length();
    bool res = true;
    for (int i = 0; i < size; ++i)
    {
        if (str[i] != str[size - i - 1])
        {
            res = false;
            break;
        }
    }
    return res;
}

int subpalindrom(string str)
{
    int num = 0;
    int size = str.length();
    for (int i = 0; i < size; ++i)
    {
        for (int j = 1; j <= size - i; ++j)
        {
            string substring = str.substr(i, j);
            if (isPalindrom(substring))
                ++num;
        }
    }
    return num;
}

int main()
{
    string str = "";
    cin >> str;
    cout << subpalindrom(str);
    return 0;
}