class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(), a.end());
        long long ans = LLONG_MAX;
        for (int i = 0; i <= n - m; i++) {
            ans = min(ans, a[i + m - 1] - a[i]);
        }
        return ans;
    
    }  
};