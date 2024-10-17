class Solution {
public:
    bool isPossible(vector<int> arr, int n, int m, int mid){
        int subarrayCount = 1;
        int arraySum = 0;
        
        for(int i=0;i<n;i++){
            if(arraySum + arr[i] <= mid){
                arraySum += arr[i];
            }
            else{
                subarrayCount++;
                if(subarrayCount > m || arr[i] > mid){
                    return false;
                }
                arraySum = arr[i];
            }
        }
        
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();

        if(m>n){
            return -1;
        }
        
        int s = 0;
        
        int sum = 0;
        
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        
        int e = sum;
        
        int ans = 0;
        
        while(s<=e){
            int mid = s+(e-s)/2;
            if(isPossible(nums,n,m,mid)){
                e = mid-1;
                ans = mid;
            }
            else{
                s = mid+1;
            }
        }
        
        return ans;    
    }
};