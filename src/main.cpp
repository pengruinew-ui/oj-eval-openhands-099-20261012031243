#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    
    vector<vector<int>> lake(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> lake[i][j];
        }
    }
    
    // Directions for adjacent cells (up, down, left, right)
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int maxFish = 0;
    
    // DFS to find connected water cells and sum fish
    function<int(int, int)> dfs = [&](int row, int col) {
        if (row < 0 || row >= m || col < 0 || col >= n || 
            visited[row][col] || lake[row][col] == 0) {
            return 0;
        }
        
        visited[row][col] = true;
        int fish = lake[row][col];
        
        // Explore all four adjacent directions
        for (auto& dir : directions) {
            int newRow = row + dir.first;
            int newCol = col + dir.second;
            fish += dfs(newRow, newCol);
        }
        
        return fish;
    };
    
    // Try starting from each water cell
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (lake[i][j] > 0 && !visited[i][j]) {
                int currentFish = dfs(i, j);
                maxFish = max(maxFish, currentFish);
            }
        }
    }
    
    cout << maxFish << endl;
    
    return 0;
}