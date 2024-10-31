class Solution {
public:
    int maxProduct(vector<int>& nums) {
    
        int maxi_left = INT_MIN,maxi_right = INT_MIN;
        int prod=1;

        for(int i=0;i<nums.size();i++)
        {
          prod*=nums[i];
          maxi_left=max(prod,maxi_left);
          if(prod==0)
           prod=1;
        }
        prod=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
          prod*=nums[i];
          maxi_right=max(prod,maxi_right);
          if(prod==0)
           prod=1;
        }
        return max(maxi_left,maxi_right);
    }
};