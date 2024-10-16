class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        unordered_map<int,int> mp;
        for(auto x : arr){
            mp[x]++;
        }
        
        int i=1;
        
        while(true){
            if(mp.find(i) != mp.end()){
                i++;
            }
            else
                break;
        }
        
        return i;
    }
};