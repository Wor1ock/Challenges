#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> prefix_function(string s)
{
	int n = (int)s.length();
	vector<int> pi(n);
	for (int i = 1; i < n; ++i)
	{
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])
			++j;
		pi[i] = j;
	}
	return pi;
}

int findBase(const string str)
{
	vector<int> z(prefix_function(str));
	int n = str.length();
	int base = n - z.back();
	return base;
}

int main()
{
	string str = "";
	cin >> str;

	int base = findBase(str);
	cout << base;
	return 0;
}