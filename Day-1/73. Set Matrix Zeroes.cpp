class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        set<int> ith;
        set<int> jth;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
                    ith.insert(i);
                    jth.insert(j);
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(ith.find(i)!=ith.end() or jth.find(j)!= jth.end()){
                    matrix[i][j]=0;
                }
            }
        }
    }
};