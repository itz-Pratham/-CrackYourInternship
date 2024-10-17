class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(int i=0;i<s.size();i++){

            if(!st.empty() && st.top().first == s[i]) st.top().second++;
            else st.push({s[i],1});

            if(st.top().second == k){
                st.pop();
            }
        }

        string res = "";

        while(!st.empty()){
            res = string(st.top().second, st.top().first) + res;
            st.pop();
        }

        return res;
    }
};