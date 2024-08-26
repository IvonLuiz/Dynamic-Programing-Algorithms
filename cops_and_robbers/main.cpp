#include <iostream>
#include <vector>
using namespace std;

// Helper function to perform Depth-First Search (DFS) to find a path
bool dfs(vector<vector<int>>& maze, int x, int y, vector<vector<bool>>& visited) {
    // Reach last position
    if (x == 4 && y == 4)
        return true;
    
    // Mark the current position as visited
    visited[x][y] = true;
    
    // Movement vectors (right, down, left, up)
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    // Try moving in all directions
    for (int i = 0; i < 4; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        // Check if the new position is valid and not yet visited
        if (newX >= 0 && newX < 5 && newY >= 0 && newY < 5 && 
            maze[newX][newY] == 0 && !visited[newX][newY]) {
            // Perform the search from the new position
            if (dfs(maze, newX, newY, visited))
                return true;
        }
    }
    
    // If all attempts fail, backtrack to the previous position
    return false;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        vector<vector<int>> maze(5, vector<int>(5));
        vector<vector<bool>> visited(5, vector<bool>(5, false));

        // Read the maze matrix
        for (int i = 0; i < 5; ++i)
            for (int j = 0; j < 5; ++j)
                cin >> maze[i][j];

        // Check if there is a path from the start (0,0) to the end (4,4)
        if (dfs(maze, 0, 0, visited)) {
            cout << "COPS" << endl;
        } else {
            cout << "ROBBERS" << endl;
        }
    }

    return 0;
}
