class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> count;

        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
        }

        vector<int> ans;

        for(auto x : count){
            if(x.second >=2)
                ans.push_back(x.first);
            continue;
        }

        return ans;
    }
};