class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        int n = nums2.size();
        vector<int> out(n,-1);

        for (int i = n - 1; i >= 0; i--) {

            while (!s.empty() and s.top() <= nums2[i]) {
                s.pop();
            }

            if (s.empty()) {
                out[i] = -1;
            } else {
                out[i] = s.top();
            }

            s.push(nums2[i]);
        }

        vector<int> res(nums1.size());
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            mp[nums2[i]] = i;
        }

        for(int i=0;i<nums1.size();i++){
            res[i] = out[mp[nums1[i]]];
        }

        return res;
    }
};