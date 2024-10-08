class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());
        set<vector<int>> s;
        vector<vector<int>> out;
        int n = nums.size();
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                int k = j + 1;
                int l = n - 1;
            long long N_target = (long long)target - (long long)nums[i] - (long long)nums[j];
                while(k < l){
                    if(nums[k] + nums[l] > N_target){
                        l--;
                    }
                    else if(nums[k] + nums[l] < N_target){
                        k++;
                    } 
                    else{
                        s.insert({nums[i],nums[j],nums[k],nums[l]});
                        l--;
                        k++;
                    }
                }
            }
        }
        for(auto x : s)
        out.push_back(x);
        return out;
    }
};