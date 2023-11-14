#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int p = 257;
const long long m = 1e9 + 7;
vector<long long> hash_value;
vector<long long> p_pow;

void prefix_hash(const string &s)
{
    hash_value.push_back(0);
    p_pow.push_back(1);
    int n = s.length();

    for (int i = 1; i < n + 1; ++i)
    {
        hash_value.push_back((hash_value[i - 1] * p + ((int)s[i])) % m);
        p_pow.push_back((p_pow[i - 1] * p) % m);
    }
}

bool compare_substrings(const string &input_string, int start1, int start2, int length)
{
    int hash1 = (hash_value[start1 + length - 1] + hash_value[start2 - 1] * p_pow[length]) % m;
    int hash2 = (hash_value[start2 + length - 1] + hash_value[start1 - 1] * p_pow[length]) % m;
    return hash1 == hash2;
}

int main()
{
    string str;
    cin >> str;
    str = " " + str;
    int k;
    cin >> k;

    prefix_hash(str);

    int start1, start2, length;
    while (k--)
    {
        cin >> length >> start1 >> start2;

        bool result = compare_substrings(str, ++start1, ++start2, length);
        if (result)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}
