#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSquareSize(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<int> prevRow(m, 0);
    vector<int> currRow(m, 0);
    int maxSquareSize = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 1) {
                currRow[j] = 1;
                if (i > 0 && j > 0)
                    currRow[j] += min({prevRow[j], currRow[j-1], prevRow[j-1]});
                maxSquareSize = max(maxSquareSize, currRow[j]);
            } else
                currRow[j] = 0;
        }
        prevRow = currRow;
    }

    return maxSquareSize;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> grid[i][j];

    cout << maxSquareSize(grid) << endl;
    return 0;
}
