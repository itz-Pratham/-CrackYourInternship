class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> count;

        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
        }

        for(auto x : count)
        {
            if(x.second>=2)
                return x.first;
            continue;
        }

        return 0;
    }
};