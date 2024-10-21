class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        int ans = INT_MIN;
        for(int i=0;i<k;i++){
            ans = nums[i];
        }
        return ans;
    }
};