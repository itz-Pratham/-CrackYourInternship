class Solution {
  public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        int minTime = -1;
        vector<int> dx {0, 0, 1, -1};
        vector<int> dy {1, -1, 0, 0};
        while(q.empty() == false){
            minTime++;
            int sz = q.size();
            for(int k = 0; k < sz; k++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++){
                    int xdx = x + dx[i];
                    int ydy = y + dy[i];
                    if(xdx >= 0 && xdx < m && ydy >= 0 && ydy < n && grid[xdx][ydy] == 1){
                        grid[xdx][ydy] = 2;
                        q.push({xdx, ydy});
                    }
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return minTime == -1 ? 0 : minTime;
    }
};
