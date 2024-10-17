class Solution {
public:

    int n;

    set<vector<int>> ans;

    void f(vector<int> inp,int i){
        
        //base case

        if(i==n){
            ans.insert(inp);
            return;
        }

        // recursive case
        f(inp,i+1);

        for(int j=i+1;j<n;j++){
            swap(inp[i],inp[j]);
            f(inp,i+1);
            swap(inp[i],inp[j]);  // backtracking
        }

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        f(nums,0);
        vector<vector<int>> res;
        for (auto& it : ans) {
        res.push_back(it);
        }
        return res;
    }
};