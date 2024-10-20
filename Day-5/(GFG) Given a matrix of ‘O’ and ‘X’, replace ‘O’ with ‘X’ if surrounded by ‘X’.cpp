// Algorithm:

// Traverse the given matrix and replace all ‘O’ with a special character ‘-‘.
// Traverse four edges of given matrix and call floodFill(‘-‘, ‘O’) for every ‘-‘ on edges. The remaining ‘-‘ are the characters that indicate ‘O’s (in the original matrix) to be replaced by ‘X’.
// Traverse the matrix and replace all ‘-‘s with ‘X’s.

class Solution{
    public:
    void floodFillUtil(char mat[][N], int x, int y, char prevV, char newV)
    {
        // Base cases
        if (x < 0 || x >= M || y < 0 || y >= N)
            return;
        if (mat[x][y] != prevV)
            return;

        mat[x][y] = newV;
    
        // Recur for north, east, south and west
        floodFillUtil(mat, x+1, y, prevV, newV);
        floodFillUtil(mat, x-1, y, prevV, newV);
        floodFillUtil(mat, x, y+1, prevV, newV);
        floodFillUtil(mat, x, y-1, prevV, newV);
    }
    
    int replaceSurrounded(char mat[][N])
    {
    for (int i=0; i<M; i++)
        for (int j=0; j<N; j++)
            if (mat[i][j] == 'O')
                mat[i][j] = '-';

    for (int i=0; i<M; i++)   // Left side
        if (mat[i][0] == '-')
            floodFillUtil(mat, i, 0, '-', 'O');
    for (int i=0; i<M; i++)  //  Right side
        if (mat[i][N-1] == '-')
            floodFillUtil(mat, i, N-1, '-', 'O');
    for (int i=0; i<N; i++)   // Top side
        if (mat[0][i] == '-')
            floodFillUtil(mat, 0, i, '-', 'O');
    for (int i=0; i<N; i++)  // Bottom side
        if (mat[M-1][i] == '-')
            floodFillUtil(mat, M-1, i, '-', 'O');

    for (int i=0; i<M; i++)
        for (int j=0; j<N; j++)
            if (mat[i][j] == '-')
                mat[i][j] = 'X';
    
    }
};