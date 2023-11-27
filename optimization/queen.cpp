#include <iostream>
#include <vector>

using namespace std;

int count = 0;

bool isSafe(vector<vector<int>>& grid, int row, int col, int N) {
    for (int i = 0; i < N; ++i)
        if (grid[row][i] == 1)
            return false;
    
    for (int i = 0; i < N; ++i)
        if (grid[i][col] == 1)
            return false;
    
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
        if (grid[i][j] == 1) 
            return false;
    
    for (int i = row, j = col; i < N && j < N; ++i, ++j)
        if (grid[i][j] == 1)
            return false;
    
    for (int i = row, j = col; i >= 0 && j < N; --i, ++j)
        if (grid[i][j] == 1)
            return false;
    
    for (int i = row, j = col; i < N && j >= 0; ++i, --j)
        if (grid[i][j] == 1)
            return false;
    
    return true;
}

void solveNDinosours(vector<vector<int>>& grid, int col, int N) {
    if (col == N) {
        ++count;
        return;
    }
    
    for (int i = 0; i < N; ++i)
        if (isSafe(grid, i, col, N)) {
            grid[i][col] = 1;
            solveNDinosours(grid, col + 1, N);
            grid[i][col] = 0;
        }
}

int main() {
    int N;
    cin >> N;
    
    vector<vector<int>> grid(N, vector<int>(N, 0));
    solveNDinosours(grid, 0, N);
    cout << count << endl;
    
    return 0;
}