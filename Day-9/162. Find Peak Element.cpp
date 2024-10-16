class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n= nums.size();
        if(n==1)
            return 0;
        
        if(n==2){
            if((nums[0]) > nums[1]) return 0;
            else    return 1;
        }

        int i=1;

        if(n>2){
            if(nums[0]>nums[1])    return 0;

            for(i=1;i<n-1;i++){
                if(nums[i]>nums[i+1] && nums[i]>nums[i-1]){
                    break;
                }
            }
        }

        return i;
    }

};