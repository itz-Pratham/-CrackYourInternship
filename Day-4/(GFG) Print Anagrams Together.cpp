class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& strs) {
        int n = strs.size();

        vector<vector<string>> res;

        unordered_map<string, vector<string>> alpha;

        for(int i=0;i<n;i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            alpha[temp].push_back(strs[i]);
        }

        for(auto it : alpha){
            res.push_back(it.second);
        }

        return res;
    }
};