#include <iostream>
#include <string>
#include <vector>

using namespace std;

int countPalindromeSubstrings(const string& s) {
    int n = s.length();
    vector<int> d1(n), d2(n);

    int l = 0, r = -1;
    for (int i = 0; i < n; ++i) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k])
            ++k;
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }

    l = 0;
    r = -1;
    for (int i = 0; i < n; ++i) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k])
            ++k;
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k;
        }
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        count += d1[i];
        count += d2[i];
    }

    return count;
}

int main() {
    string input;
    cin >> input;

    int result = countPalindromeSubstrings(input);
    cout << result << endl;

    return 0;
}
