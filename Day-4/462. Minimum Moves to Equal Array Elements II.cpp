class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mid = 0;
        if(nums.size()%2==0){
            mid = (nums.size()/2)-1;
        }
        else{
            mid = nums.size()/2;
        }
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            ans += abs(nums[mid]-nums[i]);
        }

        return ans;
    }
};