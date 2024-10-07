class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();
        vector<int> ex_nums;
        for(int i=0;i<n-1;i++){
            if(nums[i]!=nums[i+1]){
                ex_nums.push_back(nums[i]);
            }
            continue;
        }
        ex_nums.push_back(nums[n-1]);

        int cnt = ex_nums.size();

        for(int i=0;i<cnt;i++){
            nums[i]=ex_nums[i];
        }

        return cnt;
        
    }
};