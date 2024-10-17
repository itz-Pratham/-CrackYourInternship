class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &var, int sum, int index, int target, vector<int> &a){

        // Base Case

        if(target==0){
            ans.push_back(var);
            return;
        }

        // if(index == a.size() || sum > target){
        //     return;
        // }
        
        // Recursive case
        for(int i=index;i<a.size();i++){
            if(i>index && a[i]==a[i-1]) continue;
            if(a[i]>target) break;
            var.push_back(a[i]);
            solve(ans, var, sum, i + 1, target - a[i], a);
            var.pop_back();
        }

        //solve(ans, var, sum, index + 1, target , a);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> var;
        solve(ans,var,0,0,target,candidates);
        return ans;
    }
};