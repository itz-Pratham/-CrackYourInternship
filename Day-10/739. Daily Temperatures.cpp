class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> s;
        int n = temperatures.size();
        vector<int> out(n,0);

        for (int i = n - 1; i >= 0; i--) {


            while (!s.empty() and s.top().first <= temperatures[i]) {
                s.pop();
            }

            if (s.empty()) {
                out[i] = 0;
            } else {
                out[i] = (s.top().second)-i;
            }

            s.push({temperatures[i],i});
        }

        return out;
    }
};