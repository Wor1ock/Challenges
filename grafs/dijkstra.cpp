#include <iostream>
#include <vector>

using namespace std;
void print(vector<vector<int>> mat)
{
    cout << endl;
    for (int i = 0; i < mat.size(); ++i)
    {
        for (int j = 0; j < mat.size(); ++j)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int n, start, final;
    cin >> n >> start >> final;
    int size = n + 1;

    vector<vector<int>> mat(size, vector<int>(size, -1));
    for (int i = 1; i < size; ++i)
        for (int j = 1; j < size; ++j)
            cin >> mat[i][j];

    print(mat);

    return 0;
}