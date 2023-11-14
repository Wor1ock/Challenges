#include <iostream>
#include <algorithm>

using namespace std;

bool isanagramm(const string str1, const string str2)
{
    if (str1.length() != str2.length())
        return false;

    string strsort1 = str1;
    sort(strsort1.begin(), strsort1.end());
    string strsort2 = str2;
    sort(strsort2.begin(), strsort2.end());

    return strsort1 == strsort2;
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    if (isanagramm(str1, str2))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}