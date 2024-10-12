class Solution {
  public:
    void generatePermutations(vector<int> &inp, int i, vector<vector<int>> &ans) {
        // Base case
        if (i == inp.size()) {
            ans.push_back(inp);
            return;
        }

        for (int j = i; j < inp.size(); j++) {
            // Skip duplicates
            if (j != i && inp[j] == inp[i]) {
                continue;
            }

            swap(inp[i], inp[j]);
            generatePermutations(inp, i + 1, ans);
            swap(inp[i], inp[j]);  // Backtracking step
        }
    }
    
    vector<vector<int>> uniquePerms(vector<int> &arr, int n) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        generatePermutations(arr, 0, ans);
        
        // Removing duplicates .. important step for ordered pairs ...
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};