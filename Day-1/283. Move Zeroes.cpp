class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> res;
        int count = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                count++;
            }
            else{
                res.push_back(nums[i]);
            }
        }
        nums.clear();
        for(auto im : res){
            nums.push_back(im);
        }
        for(int i=0;i<count;i++){
            nums.push_back(0);
        }
    }
};