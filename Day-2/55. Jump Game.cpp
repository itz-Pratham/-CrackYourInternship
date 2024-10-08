class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int last = n - 1; 
        for(int i=n-2;i>=0;i--)
            if((nums[i]+i)>=last)
                last = i;    
        if(last==0) return true;
        return false;
    }
};