class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> freq(n,0);
        freq[0]=nums[0];
        for(int i=1;i<n;i++){
            freq[i]=nums[i]+freq[i-1];
        }
        int count=0;
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            if(freq[i]==k) 
                count++; // for single digit matches
            if(map.find(freq[i]-k)!=map.end()) 
                count+= map[freq[i]-k];
            map[freq[i]]++;
        }
        return count;
    }
};