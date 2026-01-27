// Direction arrays - DRY principle
vector<int> dx = {0, 1, 0, -1};  // Right, Down, Left, Up
vector<int> dy = {1, 0, -1, 0};

// 8 directions (for knight moves, etc.)
vector<int> dx8 = {-1, -1, 0, 1, 1, 1, 0, -1};
vector<int> dy8 = {0, 1, 1, 1, 0, -1, -1, -1};

bool isValid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

// Iteration patterns
for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
        // Row-major traversal (cache friendly)
        process(grid[i][j]);
    }
}

// Spiral traversal trick
int top = 0, bottom = n-1, left = 0, right = m-1;
while(top <= bottom && left <= right) {
    // Move right, down, left, up
    for(int j = left; j <= right; j++) process(grid[top][j]);
    top++;
    for(int i = top; i <= bottom; i++) process(grid[i][right]);
    right--;
    if(top <= bottom) {
        for(int j = right; j >= left; j--) process(grid[bottom][j]);
        bottom--;
    }
    if(left <= right) {
        for(int i = bottom; i >= top; i--) process(grid[i][left]);
        left++;
    }
}