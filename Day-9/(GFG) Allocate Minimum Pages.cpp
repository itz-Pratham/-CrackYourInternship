class Solution {
  public:
    bool isPossible(int arr[], int n, int m, long long mid){
        int studentCount = 1;
        int pageSum = 0;
        
        for(int i=0;i<n;i++){
            if(pageSum + arr[i] <= mid){
                pageSum += arr[i];
            }
            else{
                studentCount++;
                if(studentCount > m || arr[i] > mid){
                    return false;
                }
                pageSum = arr[i];
            }
        }
        
        return true;
    }
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        if(m>n){
            return -1;
        }
        
        long long s = 0;
        
        long long sum = 0;
        
        for(int i=0;i<n;i++){
            sum += arr[i];
        }
        
        long long e = sum;
        
        long long ans = 0;
        
        while(s<=e){
            long long mid = s+(e-s)/2;
            if(isPossible(arr,n,m,mid)){
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