class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        unordered_map<int,int> count;
        for(int i=0;i<arr.size();i++){
            if(count.find(arr[i]+x)!=count.end() || count.find(arr[i]-x)!=count.end())
                return 1;
            else
                count[arr[i]]++;
        }
        return -1;
    }
};