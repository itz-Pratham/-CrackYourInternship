class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        
        int n = mat.size();

        int top = 0,bottom = n-1,left = 0,right = n-1,count=0;

        while(top<bottom && left<right)
        {
            count;
            for(int i=0; i<bottom-count; i++)
            {
                int t =mat[top][left + i];

                mat[top][left + i] = mat[bottom - i][left];

                mat[bottom - i][left] = mat[bottom][right - i];

                mat[bottom][right - i] = mat[top + i][right];

                mat[top + i][right] = t;
            }
            left++;
            right--;
            top++;
            bottom--;
            count++;
        }

        return ;
    }
};