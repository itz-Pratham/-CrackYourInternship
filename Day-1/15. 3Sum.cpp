#include<bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        set<vector<int>> s;
        vector<vector<int>> out;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size()-2;i++)
        {
            int j=i+1;
            int k=nums.size()-1;
            while(j<k)
            {
                int sum =nums[i]+nums[j]+nums[k];
                if(sum==0){
                    s.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                } else if(sum>0){
                    k--;
                }else
                    j++;
            }
        }

        for(auto ans : s){
            out.push_back(ans);
        }

        return out;
    }
};