class Solution {
  public:
    bool isPossible(int k, vector<int> &a, vector<int> &b) {
        // Your code goes here

        sort(a.begin(),a.end());

        sort(b.begin(), b.end(), greater<int>());

        for (int i = 0; i < a.size() ; i++)
            if (a[i] + b[i] < k)
                return false;
    
        return true;
    }
};