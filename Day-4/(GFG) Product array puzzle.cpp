class Solution {
  public:
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        long long int n = nums.size();
        vector<long long int> answer(n);
        vector<long long int> prefixSum(n);
        vector<long long int> suffixSum(n);

        prefixSum[0]=1;

        for(int i=1;i<n;i++){
            prefixSum[i]=prefixSum[i-1]*nums[i-1];
        }

        suffixSum[n-1]=1;

        for(int i=n-2;i>=0;i--){
            suffixSum[i]=suffixSum[i+1]*nums[i+1];
        }

        for(int i=0;i<n;i++){
            answer[i]=prefixSum[i]*suffixSum[i];
        }

        return answer;
    }
};