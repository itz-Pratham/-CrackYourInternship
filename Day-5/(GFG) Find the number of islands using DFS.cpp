// Follow the steps below to solve the problem:

// Initialize count = 0 and boolean matrix, visited[][] to false.
// For each cell of the input matrix check if the value of the current cell is 1 and is not visited , call for the DFS for all its 8 neighboring cells.
// If the neighbor is safe to visit and is not visited already Call DFS recursively and Increment count by 1
// Return count as the final answer.


class Solution{
    public:
    bool isSafe(vector<vector<char>>& M, int r, int c, 
                vector<vector<bool>>& visited) {
        int ROW = M.size();
        int COL = M[0].size();
    
        // r is in range, c is in range, value is 1 and not 
        // yet visited
        return (r >= 0) && (r < ROW) && (c >= 0) && (c < COL) && 
                            (M[r][c] == '1' && !visited[r][c]);
    }

    void DFS(vector<vector<char>>& M, int r, int c,
            vector<vector<bool>>& visited) {

        vector<int> rNbr = { -1, -1, -1, 0, 0, 1, 1, 1 };
        vector<int> cNbr = { -1, 0, 1, -1, 1, -1, 0, 1 };

        visited[r][c] = true;

        for (int k = 0; k < 8; ++k) {
            int newR = r + rNbr[k];
            int newC = c + cNbr[k];
            if (isSafe(M, newR, newC, visited)) {
                DFS(M, newR, newC, visited);
            }
        }
    }

    int countIslands(vector<vector<char>>& M) {
        int ROW = M.size();
        int COL = M[0].size();

        vector<vector<bool>> visited(ROW, vector<bool>(COL, false));

        int count = 0;
        for (int r = 0; r < ROW; ++r) {
            for (int c = 0; c < COL; ++c) {

                if (M[r][c] == '1' && !visited[r][c]) {

                    DFS(M, r, c, visited);

                    ++count;
                }
            }
        }
        return count;
    }
};