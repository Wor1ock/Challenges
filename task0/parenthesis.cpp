#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isProperlyNested(const string &sequence)
{
    stack<char> s;
    for (char bracket : sequence)
    {
        if (bracket == '(' || bracket == '[' || bracket == '{')
            s.push(bracket);
        else
        {
            if (s.empty())
                return false;
            if ((bracket == ')' && s.top() != '(') ||
                (bracket == ']' && s.top() != '[') ||
                (bracket == '}' && s.top() != '{'))
                return false;
            s.pop();
        }
    }
    return s.empty();
}

int main()
{
    string input;
    cin >> input;
    if (isProperlyNested(input))
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}
