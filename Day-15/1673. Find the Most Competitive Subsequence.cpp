class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> st;
        int rem = nums.size()-k;

        for(int i=0;i<nums.size();i++){
            while((!st.empty()) && (rem>0) && (nums[i]<st.top())){
                st.pop();
                rem--;
            }
            st.push(nums[i]);
        }
        while(rem){
            st.pop();
            rem--;
        }
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());

        return res;
    }
};