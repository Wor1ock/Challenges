#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> mirrorZFunction(const string& s) {
    int n = s.length();
    vector<int> zMirror(n);
    int l = 0, r = 0; // Текущий отрезок [l, r], в котором уже посчитана зеркальная Z-функция

    for (int i = 1; i < n; i++) {
        if (i <= r) {
            zMirror[i] = min(r - i + 1, zMirror[i - l]);
        }
        while (i + zMirror[i] < n && s[zMirror[i]] == s[i + zMirror[i]]) {
            zMirror[i]++;
        }
        if (i + zMirror[i] - 1 > r) {
            l = i;
            r = i + zMirror[i] - 1;
        }
    }

    return zMirror;
}

int main() {
    string input = "abacaba";
    vector<int> result = mirrorZFunction(input);
    cout << "Mirror Z-Function for string \"" << input << "\": ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
